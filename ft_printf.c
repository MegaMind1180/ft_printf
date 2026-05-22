#include "ft_printf.h"
int	ft_whatisit(char str, va_list *arg);
void				ft_putchar_fd(char c, int fd);


int	ft_printf(char *str, ...)
{
	va_list	arg;
	char	whatisit;
	size_t	i;
	size_t	count;
	
	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = ft_whatisit(str[i], &arg) + count;
		}
		i++;
	}
	return (count);
}

int	ft_whatisit(char str, va_list *arg)
{
	size_t	i;
	char	*print;

	i = 0;
	if (str == 'c')
	{
		ft_putchar_fd(va_arg(*arg, int), 1);
		i++;
	}
	if (str == 's')
		i = ft_putstr(va_arg(*arg, char *), 1);


	return (i);
}

