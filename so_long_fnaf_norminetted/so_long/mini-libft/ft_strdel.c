/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:51:16 by mivendit          #+#    #+#             */
/*   Updated: 2023/04/24 11:51:17 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as == 0)
		return ;
	if (*as != 0)
	{
		free(*as);
		*as = 0;
	}
}