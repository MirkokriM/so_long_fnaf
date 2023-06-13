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

#include "../include/so_long.h"

void	free_vars(t_game *game)
{
	int	i;

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

void	move_condition(t_game *game, int id)
{
	if (id == W || id == UP)
		direction_w(id, game);
	else if (id == S || id == DOWN)
		direction_s(id, game);
	else if (id == A || id == LEFT)
		direction_a(id, game);
	else if (id == D || id == RIGHT)
		direction_d(id, game);
	return ;
}
