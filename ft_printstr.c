#include "ft_printf.h"

int ft_strlen(char *);

int    ft_putstr(char *s, int fd)
{
        int  i;

        i = 0;
        while (i < ft_strlen(s))
        {
               if (write(fd, &s[i], 1) == -1)
                       return (-1);
               i++;
        }
		return (i);
}
