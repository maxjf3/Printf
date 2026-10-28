/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/28 02:20:44 by max              ###   ########.fr       */
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
	else
		return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'd')
				ft_print_int(ap, 1);
			else if (s[i + 1] == 's')
				ft_print_str(ap);
			else if (s[i + 1] == 'c')
				ft_print_int(ap, 2);
			else
				return (-1);
			i += 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}