/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:25:45 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 01:00:09 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void    put_correct_image(t_game *game, int i, int j, int map_i, int map_j)
{      
    draw_move(game);
    if (game->vars->map[map_i][map_j] == '1')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_wall, j, i);
    else if(game->vars->map[map_i][map_j] == 'P')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, j, i);
    else if(game->vars->map[map_i][map_j] == 'C')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_collect, j, i);
    else if(game->vars->map[map_i][map_j] == 'E')
    {
        if(game->vars->index_collect != 0)
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_exit1, j, i);
        else if(game->vars->index_collect == 0)
             mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_exit, j, i);
    }
    else if(game->vars->map[map_i][map_j] == 'G')
    {
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_enemy, j, i);
        if (game->enemy_frame == 1)
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_enemy, j, i);
        else if (game->enemy_frame == 2)
             mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_enemy2, j, i);
    }
    else 
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, j, i);
}

void place_image(t_game *game)
{
    int i;
    int j;
    int map_i;
    int map_j;

    i = 0;
    map_i = 0;
    while (i < game->y)
    {
        j = 0;
        map_j = 0;
        while (j < game->x)
        {
            put_correct_image(game, i , j, map_i, map_j);
            j += TILESIZE;
            map_j++;
        }
        i += TILESIZE;
        map_i++;
    }
}
