/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:55:28 by max               #+#    #+#             */
/*   Updated: 2026/10/29 20:54:12 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libftprintf.h"
#include "../header/libft.h"

void	ft_convert_base(va_list lst_args, char c)
{
	void 				*tmp;
	unsigned long		adr;
	int					hex;

	if (c == 'p')
	{
		(void)hex;
		tmp = va_arg(lst_args, void *);
		adr = (unsigned long)tmp;
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(adr, "0123456789abcdef");
	}
	if (c == 'x')
	{
		hex = va_arg(lst_args, int);
		ft_putnbr_base(hex, "0123456789abcdef");
	}
	if (c == 'X')
	{
		hex = va_arg(lst_args, int);
		ft_putnbr_base(hex, "0123456789ABCDEF");
	}
}