import itertools
import gettext
import abc
from typing import Tuple, List, Type
from datetime import datetime
from enum import Enum


class RandomNumberGenerator(abc.ABC):
    """Abstract class for Random Number Generators"""

    def __init__(self, seed: int = 1):
        self.seed = seed

    @abc.abstractmethod
    def sample(self):
        pass


class Mersenne(RandomNumberGenerator):
    """Random Number Generator that uses Mersenne algorithm"""

    def __init__(self, seed: int = int((datetime.utcnow() - datetime.min).total_seconds())):
        super().__init__(seed)
        self.bitmask_1 = (2 ** 32) - 1  # To get last 32 bits
        self.bitmask_2 = 2 ** 31  # To get 32nd bit
        self.bitmask_3 = (2 ** 31) - 1  # To get last 31 bits
        self.mt, self.index = self._initalize()

    def _initalize(self) -> Tuple[List[int], int]:
        """Initialize the generator from a seed"""
        # Create a length 624 list to store the state of the generator
        mt = [0 for i in range(624)]
        index = 0
        mt[0] = self.seed
        for i in range(1, 624):
            mt[i] = ((1812433253 * mt[i - 1]) ^ (
                    (mt[i - 1] >> 30) + i)) & self.bitmask_1
        return mt, index

    def _generate_numbers(self):
        """Generate an array of 624 untempered numbers"""
        for i in range(624):
            y = (self.mt[i] & self.bitmask_2) + (self.mt[(i + 1) % 624] & self.bitmask_3)
            self.mt[i] = self.mt[(i + 397) % 624] ^ (y >> 1)
            if y % 2 != 0:
                self.mt[i] ^= 2567483615

    def sample(self):
        while True:
            if self.index == 0:
                self._generate_numbers()
            y = self.mt[self.index]
            y ^= y >> 11
            y ^= (y << 7) & 2636928640
            y ^= (y << 15) & 4022730752
            y ^= y >> 18

            self.index = (self.index + 1) % 624
            yield y


class RANDU(RandomNumberGenerator):
    """Random Number Generator that uses randU algorithm"""
    def __init__(self, seed: int = int((datetime.utcnow() - datetime.min).total_seconds()),
                 c: int = 65539, m: int = 2147483648):
        super().__init__(seed)
        self.c = c
        self.m = m

    def sample(self):
        yield abs((self.c * self.seed) % self.m)


class Randomizer(Enum):
    MERSENNE = 'Mersenne', Mersenne
    RANDU = 'randU', RANDU

    def __new__(cls, *args, **kwargs):
        obj = object.__new__(cls)
        obj._value_ = args[0]
        return obj

    # ignore the first param since it's already set by __new__
    def __init__(self, _: str, goal_class: Type):
        self._goal_class_ = goal_class

    def create(self, seed: int = int((datetime.utcnow() - datetime.min).total_seconds())) -> RandomNumberGenerator:
        return self._goal_class_(seed)


class Card(object):
    # Ref: Applied PRETTY_SUITS and STR_RANKS structure
    # from https://github.com/worldveil/deuces/

    # Constant for suits and ranks
    PRETTY_SUITS = {
        "h": u"\u2660",  # spades
        "d": u"\u2764",  # hearts
        "c": u"\u2666",  # diamonds
        "s": u"\u2663",  # clubs
    }
    STR_RANKS = ["A"] + [str(__) for __ in range(2, 11)] + ["J", "Q", "K"]

    def __init__(self, suit: str, rank: int):
        if suit not in ["h", "d", "c", "s"]:
            raise Exception("Unknown Card Suit")
        if rank not in range(1, 13):
            raise Exception("Unknown Card rank")
        self.suit = suit
        self.rank = rank

    def __repr__(self) -> str:
        return self.PRETTY_SUITS[self.suit] + " " + self.STR_RANKS[self.rank - 1]

    def value_blackjack(self) -> int:
        """Return the value of a card when in the game of Blackjack.

        Input:
            card: A string which identifies the playing card.

        Returns:
            int, indicating the value of the card in blackjack rule.

        Strictly speaking, Aces can be valued at either 1 or 10, this
        implementation assumes that the value is always 1, and then determines
        later how many aces can be valued at 10.  (This occurs in
        blackjack_value.)
        """
        return (self.rank < 10) * self.rank + (self.rank >= 10) * 10

    def is_ace(self) -> bool:
        """Identify whether or not a card is an ace.

        Input:
            card: A string which identifies the playing card.

        Returns:
            true or false, depending on whether the card is an ace or not.
        """
        return self.rank == 1


class CardDeck(object):
    def __init__(self, rand_method: str, status="empty"):
        if status == "empty":
            self.cards = []
        elif status == "full":
            self.cards = [
                Card(suit, rank)
                for suit, rank in itertools.product(Card.PRETTY_SUITS, range(1, 13))
            ]
        else:
            raise Exception("Unknown deck status")
        self.randomizer = Randomizer(rand_method).create()

    def __repr__(self) -> str:
        # For output
        return str(
            [
                Card.PRETTY_SUITS[__.suit] + " " + Card.STR_RANKS[__.rank - 1]
                for __ in self.cards
            ]
        )

    def __getitem__(self, key: int) -> Card:
        # For indexing
        return self.cards[key]

    def append(self, card: Card):
        if type(card) != Card:
            raise Exception("Invalid Card")
        self.cards.append(card)

    def pop(self, position=None) -> Card:
        if position is None:
            return self.cards.pop()
        else:
            return self.cards.pop(position)

    def pop_rand(self) -> Card:
        """
        This element returns a random card from a given list of cards.
        """
        return self.cards.pop(next(self.randomizer.sample()) % len(self.cards))

    def blackjack_value(self) -> int:
        """Calculate the maximal value of a given hand in Blackjack.

        Input:
            cards: A list of strings, with each string identifying a playing card.

        Returns:
            The highest possible value of this hand if it is a legal blackjack
            hand, or -1 if it is an illegal hand.
        """

        sum_cards = sum([card.value_blackjack() for card in self.cards])
        num_aces = sum([card.is_ace() for card in self.cards])
        aces_to_use = max(int((21 - sum_cards) / 10.0), num_aces)
        final_value = sum_cards + 10 * aces_to_use

        if final_value > 21:
            return -1
        else:
            return final_value


def display(player: CardDeck, dealer: CardDeck, args):
    """Display the current information available to the player."""
    print(_("The dealer is showing: "), dealer[0])
    print(_("Your hand is: "), player)


def hit_me(args) -> bool:
    """Query the user as to whether they want another car or not.

    Returns:
        A boolean value of True or False.  True means that the user does want
        another card.
    """
    ans = ""
    while ans.lower() not in ("y", "n"):
        ans = input(_("Would you like another card? (y/n):"))
    return ans.lower() == "y"


def game(args):
    # Initialize everything

    deck = CardDeck(rand_method=args.rand_method, status="full")

    my_hand = CardDeck(rand_method=args.rand_method, status="empty")
    dealer_hand = CardDeck(rand_method=args.rand_method, status="empty")

    # Deal the initial cards
    for a in range(2):
        card = deck.pop_rand()
        my_hand.append(card)
        card = deck.pop_rand()
        dealer_hand.append(card)

    # Give the user as many cards as they want (without going bust).
    display(my_hand, dealer_hand, args)
    while hit_me(args):
        card = deck.pop_rand()
        my_hand.append(card)
        display(my_hand, dealer_hand, args)
        if my_hand.blackjack_value() < 0:
            print(_("You have gone bust!"))
            break

    # Now deal cards to the dealer:
    print(_("The dealer has: "), repr(dealer_hand))
    while 0 < dealer_hand.blackjack_value() < 17:
        card = deck.pop_rand()
        dealer_hand.append(card)
        print(_("The dealer hits"))
        print(_("The dealer has: "), repr(dealer_hand))

    if dealer_hand.blackjack_value() < 0:
        print(_("The dealer has gone bust!"))
    else:
        print(_("The dealer sticks with: "), repr(dealer_hand))

    # Determine who has won the game:
    my_total = my_hand.blackjack_value()
    dealer_total = dealer_hand.blackjack_value()
    if dealer_total == my_total:
        print(_("It's a draw!"))
    if dealer_total > my_total:
        print(_("The dealer won!"))
    if dealer_total < my_total:
        print(_("You won!"))


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="BlackJack Game")
    # Note that the rand_method argument is nor enabled in code!
    parser.add_argument(
        "--rand_method",
        default="randU",
        help="The random number generator method. Choose between 'Mersenne' and 'randU'.",
    )
    args = parser.parse_args()

    gettext.bindtextdomain("blackjack", "locale/")
    gettext.textdomain("blackjack")
    _ = gettext.gettext

    print()
    print("BlackJack")
    print("-" * 30)
    print(vars(args))
    print("-" * 30)
    print()

    game(args)

    print()
