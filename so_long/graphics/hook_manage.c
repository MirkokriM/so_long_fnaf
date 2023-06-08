/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 00:36:40 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void move(int id, t_game *game)
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
                if (id == W || id == UP) direction_W(id, game);
                else if (id == S || id == DOWN) direction_S(id, game);
                else if (id == A || id == LEFT) direction_A(id, game);
                else if (id == D || id == RIGHT) direction_D(id, game);
                return;
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

int hook_manage(int keycode, t_game *game)
{   
    if (keycode == ESC)
        close_win(&game->graph);
    else if ((keycode == W || keycode == UP) || (keycode == A || keycode == LEFT) || (keycode == D || keycode == RIGHT) || (keycode == S || keycode == DOWN))
    {
        move(keycode, game);
        game->graph.index_move++;
        draw_move(game);
    }
    return (0);
}