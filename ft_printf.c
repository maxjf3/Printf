/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/28 17:27:11 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static	void	ft_print_str(va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
}

static	void	ft_print_int(va_list ap, int type)
{
	int		d;
	char	*s;

	d = va_arg(ap, int);
	if (type == 1)
	{
		s = ft_itoa(d);
		ft_putstr_fd(s, 1);
	}
	else if (type == 2)
		ft_putchar_fd(d, 1);
	else if (type == 3)
	{
		d = va_arg(ap, unsigned int);
		s = ft_itoa(d);
		ft_putstr_fd(d, 1);
	}
	else
		return ;
}

void	ft_get_char(const char *s, va_list ap)
{
	if (*s == 'c')
		ft_print_int(ap, 1);
	if (*s == 's')
		ft_print_str(ap);
	if (*s == 'p')
		ft_print_int(ap, 2);
	if (*s == 'd')
		ft_print_int(ap, 2);
	if (*s == 'i')
		return ;
		// convert to base 10 //
	if (*s == 'u')
		ft_print_int(ap, 3);
	if (*s == 'x')
		// convert to base 16 in lowercase //
	if (*s == 'X')
		// convert to base 16 in uppercase //
	if (*s == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			ft_get_char(s, ap);
			s += 2;
		}
		else
		{
			write(1, s, 1);
			s++;
		}
	}
	va_end(ap);
	return (0);
}