/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:23:52 by max               #+#    #+#             */
/*   Updated: 2026/10/30 09:41:55 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
