/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:28 by mivendit          #+#    #+#             */
/*   Updated: 2023/02/23 09:57:20 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <limits.h>

int	ft_check(va_list param, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (format == 's')
		return (ft_putstring(va_arg(param, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (format == 'u')
		return (ft_putunsbase(va_arg(param, unsigned long),
				"0123456789", 10));
	else if (format == 'p')
		return (ft_putstring("0x")
			+ ft_putp(va_arg(param, unsigned long),
				"0123456789abcdef", 16));
	else if (format == 'x')
		return (ft_putunsbase(va_arg(param, unsigned long),
				"0123456789abcdef", 16));
	else if (format == 'X')
		return (ft_putunsbase(va_arg(param, unsigned long),
				"0123456789ABCDEF", 16));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_print(const char *format, va_list args)
{
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			printed += ft_check(args, format[i]);
			i++;
		}
		else
			printed += ft_putchar(format[i++]);
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = ft_print(format, args);
	va_end(args);
	return (printed);
}

// int main()
// {
// 	ft_printf("ft_printf: %d \n", ft_printf(" %u "), LONG_MAX);
// 	printf("printf: %d \n", printf(" %ld "), LONG_MAX);
// }