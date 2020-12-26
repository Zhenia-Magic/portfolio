# Artificial Intelligence in Marketing

## Contents:

1. Overview of the topic
2. History of AI implementation in Marketing
3. AI techniques in Marketing:
   1. Advertisement campaingns optimization based on user profile and various factors
   3. User's previous requiests to predict what he/she need to purchase next
   4. Optimal budget allocation between advertisements campaigns
4. AI integration into medical clinic's marketing
5. Conclusion
6. References



## Overview of the topic.

We live in an era of high technology. The world is changing so quickly that specialists do not have time to learn new work standards before the next ones come out. Every day brings us discoveries that can make our life more comfortable. Artificial intelligence is inextricably linked with the concept of scientific and technological progress - a tool that allows us to achieve incredible results in entirely different fields. AI is no longer science fiction, but our everyday reality. It is used in medicine, business, science, industry, and even in everyday life. Imperceptibly, it penetrates all areas of human activity and facilitates the achievement of excellent performance in them. A necessary clarification, artificial intelligence should not come close to a person in terms of mental activity. However, it should be able to perform tasks that a person can do, thereby freeing him from routine work. Of course, there are areas in which AI is sometimes superior to humans, such as in medicine (identifying diseases from photos, X-rays, or symptoms). Also, there are areas where AI is still far from perfect (the famous paradox with the elephant in the room (Rosenfeld, Zemel, & K. Tsotsos, 2018), which the AI does not notice or misidentifies because it is not trained to do so.) However, the improvement of AI algorithms occurs daily, and in the near future, AI will enter our daily lives even more.

In this paper, we look at the impact of artificial intelligence on one of the essential areas of business - marketing. Effective advertising campaigns, optimal budget allocation, understanding of the target audience have always been the priority goals of competent marketing. However, they are quite difficult to achieve not only for one person but also for a whole team of marketers because of the vast amount of information available now both about the effectiveness of specific advertising campaigns and about users interested in the product. However, AI is excellent at handling massive amounts of information and can deliver impressive results across all the criteria for successful marketing. By studying users, patterns in the effectiveness of using certain keywords, and demand trends, AI can provide any business with an optimal strategy that will achieve high results in attracting customers.



## History of AI implementation in Marketing

Despite the relatively recent beginning of its serious development, artificial intelligence has been a mystery and a dream for humanity for a long time. Ramon Llull expressed the idea of giving the machine the ability to think in 1315. However, creating such a machine was only discussed in the middle of the twentieth century, when Alan Turing (a great scientist and the founder of classical computer science) began developing the idea of machine learning in science. He became the "father" of artificial intelligence when he created the Turing machine - a machine that can emulate any machine, thereby starting the era of computers, whose functioning is based on the algorithms used in the Turing machine. According to Turing, artificial intelligence does not have to mimic the human thought process. However, it should be able to perform actions that are usually performed by a human: for example, vision or learning.

Much time has passed since the discoveries of Turing, and the doctrine of AI has advanced significantly. Starting in the 90s of the last century, AI began to enter various areas of our lives firmly. Marketing and advertising were no exception. It all started with weather forecasts. In the 1960s, Jule Gregory Charney, the founder of modern meteorology, and his colleagues created the first computer program for weather prediction (Goldberg, 2019). So, focusing on the weather forecast, sellers could highlight different products depending on the weather: for example, put umbrellas on the window in the rain, thereby increasing sales. It was possibly the first application of the AI algorithm in marketing.

One of the largest and most important early uses of AI in marketing was the recommendation system on Amazon, launched in 1998. The recommendations were user-based; thus, the algorithm searched for other users with similar interests to the user and issued a recommendation to look at the products that these people had viewed, but the user had not yet (Smith & Linden, 2017). Such a system naturally had drawbacks. It did not work accurately, because all people are different, and it is difficult to find similar people in real-time due to limited resources for online computing. However, Amazon's recommendation system gave rise to other similar systems on Netflix or Youtube.

Platforms were later launched to allow content creation without the aid of journalists or writers. The first such platform was Yahoo's Automated Insights Wordsmith platform. Further, such tools have significantly reduced the cost of content creation and made it possible to write targeted content separately for each user.

The changes also affected advertising campaigns. In 2014, the first algorithms appeared to optimize budget allocation between different advertising channels or keywords. Also, such scripts made it possible to automate the process of adjusting advertising campaigns.

2015 brought another sophisticated machine learning algorithm RankBrain to humanity, which can analyze a series of user queries in Google search and give out those links or products that the user is most likely to need based on his queries.

Recent years have shown the most rapid growth in interest in AI. Large companies and small businesses are adopting various AI algorithms to improve profitability and automate processes. Social networks and online stores use smart chatbots to reduce the cost of maintaining a call center. More and more companies are collecting user data for targeting ads. That is why the phenomenon of AI in marketing is exciting and relevant, and can also be successfully used for my clinic.

## AI techniques in Marketing:

As we have considered the basic concept of AI in marketing and its brief history, we can turn to specific mechanisms for introducing AI into various processes. We will only touch on the classic and widespread options for using AI in marketing, such as: optimizing budget allocation for various advertising companies, choosing the most appropriate keywords and changing the parameters of advertising campaigns depending on various factors, drawing up a portrait of a buyer based on collecting data from Internet resources and analyzing his activities.

### Advertisement campaingns optimization based on user profile and various factors

One of the most significant advances in AI marketing is the personalization of content and ads never seen before. If earlier marketers had to develop an approach to each customer on their own, now AI algorithms are doing everything for them, capable of developing an approach to any person based on a set of data on user activity in the network and demographic data. We will talk more about such algorithms in this part of the paper.
The Internet contains a colossal amount of data about all its users. Some of them:
- Information on social networks: age, gender, marital status
- "Traces" on the Internet: likes, reposts, group memberships, friends lists, transitions on sites
- Cookies, trackers on sites
- Websites of organizations, clubs, universities, schools and other places where a person can work or study

Thus, parse this data and collect hundreds or even thousands of different facts characterizing a person is not difficult to parse. With this amount of data, a well-trained neural network can quickly identify a potential buyer and show him the appropriate ad. For example, if a neural network receives as input a 13-year-old girl who is fond of dancing, it is unlikely to show her an advertisement for fishing rods, most likely the girl will see an advertisement for a new dance section in her city (also an important detail, since location is one of the leading ad targeting parameters ).

Also, in addition to demographic data, the analysis of visits to sites for a certain amount of time is widely used: for example, if a person looked at wedding dresses and a restaurant for a banquet, a wedding is probably planned, and this person can be offered an advertisement for a wedding bouquet.

Let us consider how targeted advertising works from the inside. After receiving responses from various users about certain ads and placing them in a matrix, the algorithm programmatically creates the input data: user matrices and ad matrices. In the nodes of the matrix - the linear representation of values of features, which reflect some parameters of users and ads, which indicate a person's preferences, or characteristics of an ad. For such an action, we can use the LightFM library for Python; it acts as a "factorization machine and learning linear embeddings for each feature" (Rival, 2018). After these steps, this library creates a new matrix (which is the product of the multiplication of two composite matrices) containing the predicted scores for all ads and all users, so that even if the person has not yet rated it, we see their expected reaction. Thus, by sorting the predicted reactions, we can show the user the most effective ad. This technique is called linear factorization. This method is quite useful in terms of accuracy and terms of the consumption of computer power. However, neural networks can be more accurate when working with targeted advertising.

The TensorRec library can be used to train the neural network used in recommending ads to users. Instead of user ratings alone, it also uses metadata about each user (age, gender, marital status) and ad (a genre of movie advertised, price). The output of the neural network is the score, the higher it is, the more likely a particular user will like the ad. Such a neural network is trained as a classical neural network for classification - comparing the obtained scores and the user's real assessment - like or dislike.

![](https://camo.githubusercontent.com/4998a64f4b2783faf2999b57c5be96dd6be74fc7/68747470733a2f2f7261772e67697468756275736572636f6e74656e742e636f6d2f6a666b69726b2f74656e736f727265632f6d61737465722f6578616d706c65732f73797374656d5f6469616772616d2e706e67)



​											*Figure 1:* Recommendation System Neural Network Basic Representation

One fascinating example of user portrait recognition algorithms is XANT (Reference 5), a tool for marketers that, among other useful features, allows you to get practical help about each user. For example, do they like to communicate on the phone, or if the marketer writes to them by email, will they immediately answer, are they friendly, and the likelihood of reaching an agreement with them. All of these beneficial aspects of the customer relationship are presented within this program.

To summarize, AI algorithms on the Internet collect vast amounts of data about users to target ads as efficiently as possible. From an ethical point of view, this issue has always been a sore subject. Many sites and social networks prohibit parsing. For example, Facebook can prosecute people who launch bots that retrieve personal data from a social network. However, many sites like Twitter let bots parse without any restrictions. Thus, it is clear that personalized ads are firmly established in people's lives and will continue to evolve rapidly.

### User's previous requiests to predict what he/she need to purchase next

In the previous part, we already started discussing how ads are targeted to a specific user, based on various factors. However, it is also essential to consider an interesting predictive mechanism for customer further desires, drawn from studying the user's past activities. We will look at different aspects of this issue.

First, the search engine is where the search for almost any product begins. What appears first in search responses is likely to be the first that a user clicks. Thus, search engine algorithms that allow real-time analysis of a user's request and give him the most relevant answers are among the most important uses of AI for marketing. With this AI, certain ads are shown where they are needed, and the user gets the best answer to their question. A great example of such an algorithm is Google's RankBrain system. It is a self-learning AI algorithm built based on various types of machine learning: reinforcement learning to learn from user feedback on search results, supervised learning to learn elements of good search responses, unsupervised learning to cluster search results by topic. RankBrain itself improves the algorithm depending on the search query: it ranks the importance of novelty, the size of the content of the results sites, the user's past searches. In case of a positive user reaction to such a change, RankBrain leaves it until the next improvement is made. If negative, it returns the old version.

Logical questions immediately arise: how does the algorithm understand our request more accurately than all past technological solutions, and how is user satisfaction assessed?

Firstly, RankBrain has implemented a new logic for searching links for unfamiliar words: now, the search does not take place on all pages on the Internet for the appearance of keywords, but on past search queries where these keywords appeared. Partially it is due to the Word2vec technology (a popular technique for language analysis and word clustering), which turns words into concepts by vectorizing them.

Secondly, to understand the user's reaction to search results, several vital parameters are used: CTR (click-through rate), time spent on the website, pogo-sticking (the phenomenon when a user visits several sites from the search results for a short time in order to find the most suitable result). The last concept is most relevant for evaluating the algorithm's effectiveness since if the user immediately left the open site, he is most likely unhappy with it.

In this way, RankBrain helps advertisers to ensure that their ads are shown only when needed.

The second aspect of past action recommendations is a great way to capture when social media ads appear with products that a user has recently viewed on another site. This phenomenon is called retargeting, and it is performed using cookies, that is, a site using cookies follows the user and reminds of the product even on other sites through advertising. This mechanism is not entirely related to machine learning, but it also reflects how an algorithm can help sell a product that the user may have forgotten about by showing it to him repeatedly.

### Optimal budget allocation between advertisements campaigns

The final application of AI that we will look at in this paper is advertising budget optimization using various mathematical tools. Facebook was the first to provide this option for advertisers placing ads on their platform. To facilitate their work, Facebook offers a campaign budget optimization option, which automatically reacts through machine learning to changes in the popularity of particular ads in a selected campaign and applies those advertising methods that are most effective at a particular moment. Thus, the algorithm maximizes the clicks that can be obtained using the advertiser's budget. Thanks to AI, a marketer no longer needs to monitor the progress of advertising campaigns around the clock for optimization, a smart algorithm does everything for it. In addition to the budget, the budget optimization settings include the bid strategy: a parameter that determines the tool's tactics: will it find the most profitable options and use them to the detriment of the rest, or will it leave approximately the same budget for each ad. Even though Facebook's campaign budget optimization algorithm is a complex and ingenious creation, it consists of simple techniques of time series analysis and mathematical optimization.

Let us try to dig deeper and understand the essence of the tool. First, an algorithm for analyzing time intervals, perhaps ARIMA or a neural network, builds predictions of the effectiveness of individual advertisements based on real-time data, such as target audience, time of day, time of year, political mood. After that, the algorithm gives a conditional rating to all possible advertisements to correctly allocate the budget specifically for effective campaigns. After that, a mathematical optimization algorithm is put into operation, which, using the conditional rating of specific ads and the current CPC for each of them, compiles equations - one for the budget, the second for the total number of clicks or response from the audience - and optimizes the variables in them in such a way as to maximize response while meeting budget. In terms of mathematical optimization, the objective function is to maximize profit (clicks or outreach), the variable is the priority of the particular adds in the advertising process, and constraints are that the budget must be within the given constraints and the bid strategy details such as the same budget for the particular advertisements. Most likely, the optimization process is carried out using mathematical analysis.

Another essential part of this process is the very selection of the most effective ads to display. According to Facebook itself, their dynamic ad system strives to show as many ads as possible within the budget. Since ads are placed on different platforms, it may turn out that, due to the significant difference in price between them, the ad will not get to the desired platform. It is one of the downsides of Facebook's AI, which, while allowing a person to share the ad with more people, can make it harder to reach the target audience of a person's product.

Thus, using simple components budget optimization mechanism is an innovative and handy tool for advertisers.

## AI integration into medical clinic's marketing

As we have looked at some of how AI can be introduced into marketing, we can discuss more specific applications of AI within the orthopedic clinic - my business.

The clinic is located in Moscow, so the primary audience is Russians. During the development of the clinic, various AI tools were introduced to optimize marketing. We will now consider how some of them work. 

So, for example, let us imagine a recommendation system for services on a clinic website. From time to time, we show the user ads for the services he most likely needs. To do this, we focus on user reactions to past service recommendations and user metadata: age, gender, past tabs visited on the clinic's website. Let us say a user watched articles on back pain and lower back pain on our website, and he is a 45-year-old man, it is logical to assume that he has back hurt and needs a massage or an appointment with an orthopedist. To automate the process of issuing such targeted recommendations, we use neural networks. They are sophisticated enough so that we will look at a simple example based on the TensorRec library for python:

First, we import needed libraries:

```python
import numpy as np
import tensorrec
```

Then, as we assume we have data for user features, item features, and interactions (which is essentially a feedback of the person on ads), we can build the model with default parameters and train it with this data.

```python
model = tensorrec.TensorRec()
model.fit(interactions, user_features, item_features, epochs=10, verbose=True)
```

Now we have trained model, so we can make predictions for all of the ads and all of the users we have.

```python
preds = model.predict(item_features=item_features,
														user_features=user_features)
```

Thus, using a simple python algorithm, we were able to implement a suitable recommendation system on our site.

Since we have dealt with the aspect of targeted recommendations on the site specifically (we examined the techniques of targeting in search engines, where there are also clinic ads, we examined in the previous parts of the work), it is time to talk about budget allocation and running advertising campaigns.

Various keywords are used for advertising the clinic, and we need to understand when we should focus on some words, and when on others to maximize the flow of potential customers to our site, reducing advertising costs or at least not increasing them. For this purpose, we can use a time series prediction system (for example, ARIMA) and see the dependencies of the growth in the popularity of specific keywords on the time of day, weather, political situation, day of the week, or month of the year are. Understanding such dependencies can enable us to build an AI bot that will remotely manage advertising campaigns to make advertising the most effective. We can also use AI, which in real-time, will predict the growth of the popularity of specific keywords, and direct the budget to them.

By the way, we can optimize the budget using the scipy library for python or the solver function in Excel. For example, the code for such a task would look like this:

```python
from scipy.optimize import minimize
from scipy.optimize import NonlinearConstraint

x = []

fun = lambda x: -1 * (0.9035313397578124 * x[0] + 0.22054701995988724 * x[1] + 0.13517397996503416 * x[2] + 0.12805955995205473 * x[3] + 0.12805955995205473 * x[4] + 0.12805955995205473 * x[5] + 0.12805955995205473 * x[6] + 0.12094513995918779 * x[7] + 0.11383071996632085 * x[8] + 0.08537303997474063 * x[9] + 0.07825861998187372 * x[10] + 0.0711441999688943 * x[11] + 0.0711441999688943 * x[12])

for i in range(13):
  x.append(1)
  
bnds = ((10, None), (10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None),(10, None))

con = lambda x: 174.0 * x[0] + 458.0 * x[1] + 323.0 * x[2] + 477.0 * x[3] + 125.0 * x[4] + 142.0 * x[5] + 347.0 * x[6] + 167.0 * x[7] + 247.0 * x[8] + 518.0 * x[9] + 178.0 * x[10] + 342.0 * x[11] + 123.0 * x[12]

nlc = NonlinearConstraint(con, 59000, 60000)
nlc1=[nlc]
for i in range(13):
	con1 = lambda x: 	 x[0]/(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]+x[12])
	nlc1.append(NonlinearConstraint(con1, 0.01,0.1))
  
res = minimize(fun, x, method='SLSQP', bounds=bnds, constraints=nlc1)

res.x
```

Here we import the necessary libraries; then we have the fun function, which we need to minimize (the coefficients in it are the weights of individual ads: they depend on the frequency of such a request in the search engine and on the percentage of responses from all requests). We need to determine the initial x values for all ads, and we make them equal to 1 (x is a relative value, something like the importance of investing in this or that ad, the higher x, the more money we invest in this ad). After that, we define the frames for x (from 10 to infinity, since we want all keywords to be used). We need to set the condition that we must meet our budget - from 59,000 to 60,000 thousand rubles and that one ad cannot be more than 10% of the rating.

After all the preparations, we use the minimize function and get the x values.

![Screenshot 2020-08-18 at 23.03.29](/Users/miss_evgenia/Library/Application Support/typora-user-images/Screenshot 2020-08-18 at 23.03.29.png)

​															*Figure 2.* Results of the optimization 

As we can see, many ads received the same rating due to our conditions for a maximum of 10%. This algorithm is imperfect, but it helps to understand what order we should budget for each type of ad.

## Conclusion

Of course, we have not covered all examples of the use of artificial intelligence in marketing. This area is now moving forward with unprecedented speed. Perhaps very soon all Internet content will be written by artificial intelligence, and a computer will read all our desires right from our head. It is excellent that our clinic can apply AI now to optimize performance and increase profitability and value for clients.

## References

1. Rosenfeld, A., Zemel, R., & K. Tsotsos, J. (2018). The Elephant in the Room.
2. Smith, B., & Linden, G. (2017). Two decades of recommender systems at amazon.com. *Ieee Internet Computing*, *21*(3). https://doi.org/10.1109/MIC.2017.72
3. Goldberg, L. (2019, January 22). A brief history of artificial intelligence in advertising. Retrieved August 15, 2020, from https://econsultancy.com/a-brief-history-of-artificial-intelligence-in-advertising/
4. Rival, S. (2018, May 4). AI in Marketing [Video]. YouTube. URL https://www.youtube.com/watch?v=FYMjXD3G__Y&lc=z23hgfkpdnfjyt0n1acdp431kuaxfkhbz5py54gjhedw03c010c
5. Playbooks Sales Engagement & Revenue Acceleration Platform. (2020, July 28). Retrieved August 18, 2020, from https://www2.xant.ai/playbooks/

