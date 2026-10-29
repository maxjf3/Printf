/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:55:28 by max               #+#    #+#             */
/*   Updated: 2026/10/29 22:22:05 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libftprintf.h"
#include "../header/libft.h"

void	ft_convert_base(va_list lst_args, char c, int *ret_len)
{
	void 				*tmp;
	unsigned long		adr;
	int					hex;

	if (c == 'p')
	{
		(void)hex;
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
	if (c == 'x')
	{
		hex = va_arg(lst_args, int);
		ft_putnbr_base((unsigned int)hex, "0123456789abcdef", ret_len);
	}
	if (c == 'X')
	{
		hex = va_arg(lst_args, int);
		ft_putnbr_base((unsigned int)hex, "0123456789ABCDEF", ret_len);
	}
}