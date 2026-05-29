#include <unistd.h>

int hexer_pointer(unsigned int n)
{
    char	*hex; 
	int		count;

	hex = "0123456789abcdef";	
	count = 0;
    if (n >= 16)
        hexer_pointer(n / 16);
    if(write(1, &hex[n % 16], 1) == -1)
    	return (-1);
    count ++;
    return(count);
}
