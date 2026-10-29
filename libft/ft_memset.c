/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:57:32 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 22:54:48 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = (unsigned char)c;
		i++;
	}
	return ((unsigned char *)s);
}
