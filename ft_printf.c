/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 12:54:40 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	ft_print_args(char *s, va_list lst_args, int *ret_len)
{
	char *res;

	if (*s == 'd')
	{
		res = ft_itoa(va_arg(lst_args, int));
		ft_putstr_fd(res, 1);
		(*ret_len) += ft_strlen(res);
		free(res);
	}
	if (*s == 'c')
	{
		ft_putchar_fd(va_arg(lst_args, int), 1);
		(*ret_len)++;
	}
	if (*s == 's')
	{
		res = va_arg(lst_args, char *);
		ft_putstr_fd(res, 1);
		(*ret_len) += ft_strlen(res);
	}
}

static int	ft_get_type(char s)
{
	char	*types;

	types = "cspdiuxX%";
	while (*types)
	{
		if (*types == s)
			return (1);
		types++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst_args;
	int		ret_len;

	va_start(lst_args, s);
	ret_len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!ft_get_type(*s))
				return (-1);
			ft_print_args((char *)s, lst_args, &ret_len);
			s++;
		}
		ft_putchar_fd(*s, 1);
		s++;
		ret_len++;
	}
	va_end(lst_args);
	return (ret_len);
}