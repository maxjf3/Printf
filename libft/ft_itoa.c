/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:30:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 22:54:45 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static long	ft_getsize(long n)
{
	long	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_alloc_neg(long *n_long, int *i)
{
	char	*res;

	*n_long *= -1;
	res = ft_calloc(ft_getsize(*n_long) + 2, (sizeof(char)));
	if (!res)
		return (NULL);
	res[0] = '-';
	*i = ft_getsize(*n_long) + 1;
	res[ft_getsize(*n_long) + 1] = '\0';
	return (res);
}

static char	*ft_alloc_pos(long *n_long, int *i)
{
	char	*res;

	res = ft_calloc(ft_getsize(*n_long) + 1, (sizeof(char)));
	if (!res)
		return (NULL);
	*i = ft_getsize(*n_long);
	res[ft_getsize(*n_long)] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	n_long;

	n_long = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n_long < 0)
		res = ft_alloc_neg(&n_long, &i);
	else
		res = ft_alloc_pos(&n_long, &i);
	i--;
	if (!res)
		return (NULL);
	while (n_long > 0)
	{
		res[i] = (n_long % 10) + '0';
		n_long /= 10;
		i--;
	}
	return (res);
}
