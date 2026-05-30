/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmezgoli <wmezgoli@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:05:57 by wmezgoli          #+#    #+#             */
/*   Updated: 2026/05/17 17:05:58 by wmezgoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
		x++;
	return (x);
}

/*
#include "libft.h"

int	main(int argc, char **argv)
{
    printf("%ld", strlen(argv[1]));
}
*/
