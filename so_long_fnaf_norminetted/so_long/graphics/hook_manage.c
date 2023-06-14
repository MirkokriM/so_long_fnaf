/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 19:09:08 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move(int id, t_game *game)
{
	game->y_arrow = 0;
	game->map_i = 0;
	while (game->y_arrow < game->y)
	{
		game->x_arrow = 0;
		game->map_j = 0;
		while (game->x_arrow < game->x)
		{
			if (game->vars->map[game->map_i][game->map_j] == 'P')
			{
				move_condition(game, id);
				return ;
			}
			game->x_arrow += TILESIZE;
			game->map_j++;
		}
		game->y_arrow += TILESIZE;
		game->map_i++;
	}
}

void	draw_move(t_game *game)
{
	char	*move;
	char	*move_str;

	move = ft_itoa(game->graph.index_move);
	move_str = ft_strjoin("Move Count: ", move);
	mlx_set_font(game->graph.mlx, game->graph.win, "8x13bold");
	mlx_string_put(game->graph.mlx, game->graph.win, 10, 20,
		0xFFFFFF, move_str);
	free(move);
	free(move_str);
}

int	hook_manage(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(&game->graph);
	else if ((keycode == W || keycode == UP) \
				|| (keycode == A || keycode == LEFT) \
				|| (keycode == D || keycode == RIGHT) \
				|| (keycode == S || keycode == DOWN))
	{
		if (!game->time_count)
			game->time_count = get_time();
		move(keycode, game);
		game->graph.index_move ++;
		draw_move(game);
	}
	return (0);
}

void	exit_frame(t_game *game, int i, int j)
{
	if (game->vars->index_collect != 0)
		mlx_put_image_to_window(game->graph.mlx, \
			game->graph.win, game->graph.img_exit1, j, i);
	else if (game->vars->index_collect == 0)
		mlx_put_image_to_window(game->graph.mlx, \
			game->graph.win, game->graph.img_exit, j, i);
}

void	enemy_frame(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->graph.mlx, \
		game->graph.win, game->graph.img_enemy, j, i);
	if (game->enemy_frame == 1)
		mlx_put_image_to_window(game->graph.mlx, \
			game->graph.win, game->graph.img_enemy, j, i);
	else if (game->enemy_frame == 2)
		mlx_put_image_to_window(game->graph.mlx, \
			game->graph.win, game->graph.img_enemy2, j, i);
}
