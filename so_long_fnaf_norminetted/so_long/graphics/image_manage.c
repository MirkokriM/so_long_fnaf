/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:25:45 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/11 02:19:05 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_correct_image(t_game *game)
{
	draw_move(game);
	if (game->vars->map[game->map_i][game->map_j] == '1')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_wall, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'P')
	{
		mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
			game->graph.img_player, game->x_arrow, game->y_arrow);
		if (game->enemy_frame == 1)
			mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
				game->graph.img_player2, game->x_arrow, game->y_arrow);
		else if (game->enemy_frame == 2)
			mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
				game->graph.img_player, game->x_arrow, game->y_arrow);
	}
	else if (game->vars->map[game->map_i][game->map_j] == 'C')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
			game->graph.img_collect, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'E')
	{	
		exit_frame(game, game->y_arrow, game->x_arrow);
	}
	else if (game->vars->map[game->map_i][game->map_j] == 'G')
		enemy_frame(game, game->y_arrow, game->x_arrow);
	else
		mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
			game->graph.img_terrain, game->x_arrow, game->y_arrow);
}

void	place_image(t_game *game)
{
	game->y_arrow = 0;
	game->map_i = 0;
	while (game->y_arrow < game->y)
	{
		game->x_arrow = 0;
		game->map_j = 0;
		while (game->x_arrow < game->x)
		{
			put_correct_image(game);
			game->x_arrow += TILESIZE;
			game->map_j++;
		}
		game->y_arrow += TILESIZE;
		game->map_i++;
	}
}
