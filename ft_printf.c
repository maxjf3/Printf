/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/27 23:54:06 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		args_nb;

	i = 0;
	va_start(ap, s);
	args_nb = 0;
	while (s[i])
	{
		if(s[i] == '%')
			args_nb++;
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd')
				write(1, "Decimal", 7);
			else if (s[i] == 'c')
				write(1, "Char", 4);
			else if (s[i] == 's')
				write(1, "String", 6);
			else
				write(1, "Not valid", 9);	
			i--;
		}
		else
		{
			write(1, &s[i], 1);
		}
		i++;
	}
	printf("\nargs_nb: %d\n", args_nb);
	va_end(ap);
	return (0);
}