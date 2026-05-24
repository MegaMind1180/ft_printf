#include <unistd.h>

int	ft_putchar(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}
