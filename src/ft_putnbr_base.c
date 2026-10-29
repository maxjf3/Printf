/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:23:52 by max               #+#    #+#             */
/*   Updated: 2026/10/29 22:17:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libftprintf.h"
#include "../header/libft.h"

void	ft_putnbr_base(unsigned long adr, char *base, int *ret_len)
{
	if (adr < 16)
	{
		ft_putchar_fd(base[adr % 16], 1);
		(*ret_len)++;
	}
	else
	{
		ft_putnbr_base(adr / 16, base, ret_len);
		ft_putchar_fd(base[adr % 16], 1);
		(*ret_len)++;
	}
}