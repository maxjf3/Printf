/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 22:51:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

static void	ft_print_args2(char *s, va_list lst_args, int *ret_len)
{
	char			*str;
	unsigned int	res;

	if (*s == 'u')
	{
		res = va_arg(lst_args, unsigned int);
		str = ft_unsigned_itoa((unsigned int)res);
		ft_putstr_fd(str, 1);
		*ret_len += ft_strlen(str);
		free(str);
	}
	if (*s == 'p')
		ft_convert_base(lst_args, *s, ret_len);
	if (*s == 'x' || *s == 'X')
		ft_convert_base(lst_args, *s, ret_len);
	if (*s == '%')
	{
		ft_putchar_fd('%' , 1);
		*ret_len += 1;
	}
		
}

static void	ft_print_args(char *s, va_list lst_args, int *ret_len)
{
	char *str;

	if (*s == 'd' || *s == 'i')
	{
		str = ft_itoa(va_arg(lst_args, int));
		ft_putstr_fd(str, 1);
		*ret_len += ft_strlen(str);
		free(str);
	}
	if (*s == 'c')
	{
		ft_putchar_fd(va_arg(lst_args, int), 1);
		*ret_len += 1;
	}
	if (*s == 's')
	{
		str = va_arg(lst_args, char *);
		if (!str)
			return ;
		ft_putstr_fd(str, 1);
		*ret_len += ft_strlen(str);
	}
	if (ft_get_type(*s))
		ft_print_args2(s, lst_args, ret_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst_args;
	int		ret_len;
	int		i;

	if (!s)
		return (-1);
	va_start(lst_args, s);
	ret_len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!ft_get_type(s[i + 1]))
				return (-1);
			ft_print_args((char *)s + i + 1, lst_args, &ret_len);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			ret_len++;
			i++;
		}
	}
	va_end(lst_args);
	return (ret_len);
}