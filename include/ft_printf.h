/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:59:20 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/30 09:42:28 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putnbr_base(unsigned long adr, char *base, int *ret_len);
void	ft_convert_base(va_list lst_args, char c, int *ret_len);
char	*ft_unsigned_itoa(unsigned long n);
int		ft_printf(const char *s, ...);

#endif