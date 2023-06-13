/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:04:37 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/12 14:15:11 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void exit_game(t_game *game, int id)
{
    if (id == 1) close_winning(&game->graph);
    else if (id == 2) close_lose(&game->graph);
    exit(0);
}

void direction_W(int id, t_game *game)
{
    if (id == W || id == UP)
        if (game->vars->map[game->map_i - 1][game->map_j] != '1')
        {
            if (game->vars->map[game->map_i - 1][game->map_j] == 'C')
                game->vars->index_collect--;
            else if (game->vars->map[game->map_i - 1][game->map_j] == 'E' && game->vars->index_collect <= 0)
            {   
                
                exit_game(game, 1);
            }
            else if (game->vars->map[game->map_i - 1][game->map_j] == 'E' && game->vars->index_collect > 0)
                return ;
            else if (game->vars->map[game->map_i - 1][game->map_j] == 'G')
                exit_game(game, 2);
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i - 1][game->map_j] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow, game->y_arrow - TILESIZE);
    }
}

void    direction_S(int id, t_game *game)
{
    if (id == S || id == DOWN)
        if (game->vars->map[game->map_i + 1][game->map_j] != '1')
        {
            if (game->vars->map[game->map_i + 1][game->map_j] == 'C')
                game->vars->index_collect -= 1;
            else if (game->vars->map[game->map_i + 1][game->map_j] == 'E' && game->vars->index_collect <= 0)
                exit_game(game, 1);
            else if (game->vars->map[game->map_i + 1][game->map_j] == 'E' && game->vars->index_collect > 0)
                return ;
            else if (game->vars->map[game->map_i + 1][game->map_j] == 'G')
                exit_game(game, 2);
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i + 1][game->map_j] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow, game->y_arrow + TILESIZE);
        }
}

void direction_A(int id, t_game *game)
{   
    if (id == A || id == LEFT)
        if (game->vars->map[game->map_i][game->map_j - 1] != '1')
        {
            if (game->vars->map[game->map_i][game->map_j - 1] == 'C')
                game->vars->index_collect--;
            if (game->vars->map[game->map_i][game->map_j - 1] == 'E' && game->vars->index_collect <= 0)
                exit_game(game, 1);
            else if (game->vars->map[game->map_i][game->map_j - 1] == 'E' && game->vars->index_collect > 0)
                return ;
            else if (game->vars->map[game->map_i][game->map_j - 1] == 'G')
                exit_game(game, 2);
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i][game->map_j - 1] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow - TILESIZE, game->y_arrow);
        }
}

void direction_D(int id, t_game *game)
{   
    if (id == D || id == RIGHT)
        if (game->vars->map[game->map_i][game->map_j + 1] != '1')
        {
            if (game->vars->map[game->map_i][game->map_j + 1] == 'C')
                game->vars->index_collect--;
            if (game->vars->map[game->map_i][game->map_j] == 'E' && game->vars->index_collect <= 0)
                exit_game(game, 1);
            else if (game->vars->map[game->map_i][game->map_j +1] == 'E' && game->vars->index_collect > 0)
                return ;
            else if (game->vars->map[game->map_i][game->map_j +1] == 'G')
                exit_game(game, 2);
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i][game->map_j + 1] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow + TILESIZE, game->y_arrow);
        }
}
