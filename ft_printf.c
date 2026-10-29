/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:56:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/29 15:41:16 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

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
	//char	*str;
	(void)lst_args;

	if (*s == 'p')
		return ;
	if (*s == 'i')
		return ;
	if (*s == 'u')
		return ;
	if (*s == 'x')
		return ;
	if (*s == 'X')
		return ;
	if (*s == '%')
	{
		ft_putchar_fd('%' , 1);
		*ret_len += 1;
	}
		
}

static void	ft_print_args(char *s, va_list lst_args, int *ret_len)
{
	char *str;

	if (*s == 'd')
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