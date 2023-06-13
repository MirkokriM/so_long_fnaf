/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:57 by mivendit          #+#    #+#             */
/*   Updated: 2023/05/04 21:40:11 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstring(char *s);

int		ft_putnbr(int n);

int		ft_putunsbase(unsigned int n, char *format, int base);
int		ft_putp(unsigned long n, char *format, int base);

int		ft_printf(const char *str_format, ...);

int		ft_check(va_list param, const char format);
int		ft_print(const char *format, va_list args);
#endif
