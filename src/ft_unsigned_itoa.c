/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:30:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 20:54:22 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libftprintf.h"
#include "../header/libft.h"

static unsigned int	ft_getsize(unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_alloc(unsigned long *n, unsigned long *i)
{
	char	*res;

	res = ft_calloc(ft_getsize(*n) + 1, (sizeof(char)));
	if (!res)
		return (NULL);
	*i = ft_getsize(*n);
	res[ft_getsize(*n)] = '\0';
	return (res);
}

char	*ft_unsigned_itoa(unsigned long n)
{
	char	*res;
	unsigned long		i;

	if (n == 0)
		return (ft_strdup("0"));
	res = ft_alloc(&n, &i);
	if (!res)
		return (NULL);
	i--;
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}
