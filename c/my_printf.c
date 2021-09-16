#include <stdarg.h>
#include <unistd.h>
#include <string.h>


char* convertion(unsigned int number, int base) 
{ 
	static char helper[]= "0123456789ABCDEF";
	static char storage[50]; 
	char *p; 
	
	p = &storage[49]; 
	*p = '\0'; 
	
	do 
	{ 
		*(--p) = helper[number%base]; 
		number /= base; 
	}
    while(number != 0); 
	
	return(p); 
}

void write_char(char c)
{
    write(1, &c, 1);
}

char hex_digit(int i) {
    if ((i >= 0) && (i < 10))
        return '0' + i;
    else
        return 'a' + i - 10;
}

int print_pointer_hex(void* p0) {
    int i, counter;
    intptr_t p = (intptr_t) p0;
    counter = 2;

    write_char('0'); 
    write_char('x');

    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        write_char(hex_digit((p >> i) & 0xf));
        counter++;
    }
    return counter;
}

int my_printf(char * restrict format, ...){
        va_list ap;
        int digit, count;
        char character, *string, *num;
        void *pointer;
        unsigned int i;
        va_start(ap, format);
        char *f = format;
        count = 0;
        for(f; *f != '\0'; f++) 
	    { 
            while( (*f != '%') && (*f != '\0')) 
            { 
                write(1,f,1);
                count ++;
                f++; 
            } 

            if (*f == '\0'){
                break;
            }
		
		    f++; 

                switch(*f) {
                case 's':            
                        string = va_arg(ap, char *);
                        if (string == (char*)NULL){
                            char* nu = "(null)";
                            write(1, nu, strlen(nu));
                            count += strlen(nu);
                        }
                        else{
                            write(1, string, strlen(string));
                        count += strlen(string);}
                        break;
                case 'd':               
                        digit = va_arg(ap, int);
                        char sign = '-';
                        if(digit<0) 
						{ 
							digit = -digit;
							write(1, &sign, 1); 
						} 
						num = convertion(digit,10);
                        write(1, num, sizeof(num));
                        count += strlen(num);
                        break;
                case 'u':
                        digit = va_arg(ap, int);
						num = convertion(digit,10);
                        write(1, num, sizeof(num));
                        count += strlen(num);
                        break;

                case 'c':                    
                        character = (char) va_arg(ap, int);
                        write_char(character);
                        count += 1;
                        break;
                case 'o':                    
                        i = va_arg(ap,unsigned int); 
                        num = convertion(i,8);
						write(1, num, sizeof(num));
                        count += strlen(num);
						break; 
                case 'x':                    
                        i = va_arg(ap,unsigned int); 
						num = convertion(i,16);
						write(1, num, sizeof(num));
                        count += strlen(num);
						break; 
                case 'p':
                        pointer = va_arg(ap, void*); 
						count += print_pointer_hex(pointer);
						break; 
                }
}
        char n = '\n';
        write(1, &n, 1);
        va_end(ap);
        return count;
}


 
