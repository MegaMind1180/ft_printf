#include <unistd.h>

int ft_putnbr_hex_upper(unsigned long n)
{
    char	*hex; 
	int		count;

	hex = "0123456789ABCDEF";	
	count = 0;
    if (n >= 16)
        count += ft_putnbr_hex_upper(n / 16);
    count ++;
    if(write(1, &hex[n % 16], 1) == -1)
    	return (-1);
    return(count);
}
