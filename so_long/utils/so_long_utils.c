/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:39 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/08 18:47:59 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void free_vars(t_game *game)
{
	int i;

	i = 0;
	while (game->vars->map[i])
	{
		free(game->vars->map[i]);
		i++;
	}
	free(game->vars->map);
	free(game->vars);
	free(game);
}

char	*format_itoa(int mem, char *str, int size)
{
	while (mem > 9 || mem < -9)
	{
		if (mem < 0)
			str[size--] = -(mem % 10) + '0';
		else
			str[size--] = mem % 10 + '0';
		mem /= 10;
	}
	str[0] = (mem + '0');
	if (mem < 0)
	{
		str[0] = '-';
		str[1] = (-mem + '0');
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		mem;

	mem = n;
	size = 2;
	if (n < 0)
		size = 3;
	while ((n > 9 || n < -9) && size++)
		n /= 10;
	str = malloc((size--) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	return (format_itoa(mem, str, size));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *) malloc(sizeof(*str) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[len1++] = s2[i];
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}