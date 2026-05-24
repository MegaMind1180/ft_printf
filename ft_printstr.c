#include "ft_printf.h"

size_t    ft_putstr(char *s, int fd)
{
        size_t  i;

        i = 0;
        while (i < ft_strlen(s))
        {
               if (write(fd, &s[i], 1) == -1)
                       return (0);
               i++;
        }
		return (i);
}
