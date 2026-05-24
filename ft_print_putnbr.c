#include "ft_printf.h"

int     ft_print_putnbr(long long n)
{
        int     count;
        char    c;

        count = 0;
        if (n < 0)
        {
                ft_putchar_fd('-', 1);
                count++;
                n *= -1;
        }
        if (n >= 10)
                count += ft_print_putnbr(n / 10);
        c = n % 10 + '0';
        if (!ft_putchar(c, 1))
                return (-1);
        count++;
        return (count);
}
