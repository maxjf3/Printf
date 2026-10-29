/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:59:20 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 20:50:57 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_putnbr_base(unsigned long adr, char *base);
void	ft_convert_base(va_list lst_args, char c);
char	*ft_unsigned_itoa(unsigned long n);
int		ft_printf(const char *s, ...);

#endif