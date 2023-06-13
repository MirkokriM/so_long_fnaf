/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:53:39 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/04 21:40:00 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_putstring("-2147483648"));
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(48 + (n % 10));
	return (i);
}

int	ft_putunsbase(unsigned int n, char *format, int base)
{
	int	i;

	i = 0;
	if (n >= (unsigned int)base)
		i += ft_putunsbase(n / base, format, base);
	i += ft_putchar(format[(n % base)]);
	return (i);
}

int	ft_putp(unsigned long n, char *format, int base)
{
	int	i;

	i = 0;
	if (n >= (unsigned long)base)
		i += ft_putp(n / base, format, base);
	i += ft_putchar(format[(n % base)]);
	return (i);
}

/*La funzione ft_putchar semplicemente scrive un carattere 
sullo standard output, utilizzando la funzione write.

La funzione ft_putstring scrive una stringa carattere per 
carattere sullo standard output, utilizzando la funzione write. 
Se la stringa passata come argomento è NULL, la funzione scrive 
la stringa "(null)".

La funzione ft_putnbr scrive un numero intero sullo standard 
output come una stringa di caratteri. Se il numero è negativo, la 
funzione scrive il segno meno ("-") e poi lo converte in positivo. 
La funzione utilizza la ricorsione per scrivere ciascuna cifra del 
numero come carattere utilizzando la funzione ft_putchar. Se il numero 
è il valore minimo rappresentabile su 32 bit (-2147483648), la funzione 
scrive la stringa "-2147483648".

Infine, la funzione ft_putunsbase scrive un numero non firmato come una 
stringa di caratteri nella base specificata, utilizzando la ricorsione per 
scrivere ciascuna cifra del numero come carattere utilizzando la funzione 
ft_putchar.

Tutte le funzioni restituiscono il numero di caratteri che sono stati scritti 
sullo standard output.*/