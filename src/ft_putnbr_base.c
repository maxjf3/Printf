/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:23:52 by max               #+#    #+#             */
/*   Updated: 2026/10/29 20:54:19 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libftprintf.h"
#include "../header/libft.h"

void	ft_putnbr_base(unsigned long adr, char *base)
{
	if (adr <= 16)
		ft_putchar_fd(base[adr % 16], 1);
	else
	{
		ft_putnbr_base(adr / 16, base);
		ft_putchar_fd(base[adr % 16], 1);
	}
}