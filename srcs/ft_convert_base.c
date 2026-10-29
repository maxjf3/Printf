/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:55:28 by max               #+#    #+#             */
/*   Updated: 2026/10/29 23:38:17 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_convert_base(va_list lst_args, char c, int *ret_len)
{
	void 				*tmp;
	unsigned long		adr;
	int					hex;

	if (c == 'p')
	{
		tmp = va_arg(lst_args, void *);
		if (!tmp)
		{
			write(1, "(nil)", 5);
			(*ret_len) += 5;
			return ;
		}
		adr = (unsigned long)tmp;
		ft_putstr_fd("0x", 1);
		(*ret_len) += 2;
		ft_putnbr_base(adr, "0123456789abcdef", ret_len);
	}
	if (c == 'x' || c == 'X')
		hex = va_arg(lst_args, int);
	if (c == 'x')
		ft_putnbr_base((unsigned int)hex, "0123456789abcdef", ret_len);
	if (c == 'X')
		ft_putnbr_base((unsigned int)hex, "0123456789ABCDEF", ret_len);
	}