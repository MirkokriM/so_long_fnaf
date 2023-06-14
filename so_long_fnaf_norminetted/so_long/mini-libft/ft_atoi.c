/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:50:20 by mivendit          #+#    #+#             */
/*   Updated: 2023/04/24 11:50:21 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_num(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
		i++;
	}
	if (i > 10 || (i == 10 && ft_strcmp(string, "2147483647") > 0))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	if (ft_check_num(str))
		return (-1);
	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
