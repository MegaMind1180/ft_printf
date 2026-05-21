#include "libft.h"
int	ft_whatisit(char str);


int	ft_printf(char *str, ...)
{
	char	whatisit;
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_whatisit(str[i]);
			i++;
		}
		if (whatisit == 'c')
			
	}
}

int	ft_whatisit(char str)
{
	size_t	i;
	char	*print;

	i = 0;
	if (str == 'c')
		ft_
		
}
