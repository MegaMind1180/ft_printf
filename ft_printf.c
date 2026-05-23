#include "ft_printf.h"
int	ft_whatisit(char str, va_list *arg);
void				ft_putchar_fd(char c, int fd);


int	ft_printf(char *str, ...)
{
	va_list	arg;
	char	whatisit;
	size_t	i;
	size_t	count;

	if (!str)
		return (-1);	
	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
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
	size_t	count;
	char	*print;

	count = 0;
	if (str == 'c')
	{
		ft_putchar_fd(va_arg(*arg, int), 1);
		count++;
	}
	if (str == 's')
		count = ft_putstr(va_arg(*arg, char *), 1);
	if (str == 'i' || str == 'd')
		count = ft_print_putnbr(va_arg(*arg, int));
	if (str == 'u')
		count = ft_print_putnbr(va_arg(*arg, unsigned int));



	return (count);
}

