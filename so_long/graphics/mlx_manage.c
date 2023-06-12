/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/12 13:24:28 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	close_win(t_graph *graph)
{   
	mlx_destroy_window(graph->mlx, graph->win);
    free(graph->mlx);
	ft_printf("Game Closed\n");
	exit(0);
}

int	close_winning(t_graph *graph)
{   

    mlx_destroy_window(graph->mlx, graph->win);
    free(graph->mlx);
	ft_printf("U WIN! LMAO\n");
    ft_printf("Move Counter: %d\n", graph->index_move+1);
	exit(0);
}

int	close_lose(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
    free(graph->mlx);
	ft_printf("U DEAD! XDXD\n");
    ft_printf("Move Counter: %d\n", graph->index_move+1);
	exit(0);
}

char* select_random_collect() {
    srand(time(NULL));
    int random_number = rand() % 5 + 1;
    switch (random_number) {
        case 1:
            return COLLECT;
        case 2:
            return COLLECT2;
        case 3:
            return COLLECT3;
        case 4:
            return COLLECT4;
        case 5:
            return COLLECT5;
        default:
            return NULL;
    }
}

int update_enemy_animation(t_game *game)
{
	game->enemy_animation_timer += FRAMERATE;
    
	if (game->enemy_animation_timer >= ANIMATIONDELAY)
	{
		if (game->enemy_frame == 1)
			game->enemy_frame = 2;
		else
			game->enemy_frame = 1;
		game->enemy_animation_timer = 0;
	}
	place_image(game);
	return (0);
}


void mlx_manage(t_game *game)
{
    int img_width;
	int img_height;
    char* selected_collect = select_random_collect();
    
    game->x = (game->vars->column * TILESIZE);
    game->y = (game->vars->line * TILESIZE);
    
    game->graph.mlx = mlx_init();
    game->graph.win = mlx_new_window(game->graph.mlx, game->x, game->y, "It's been So_long");
    game->graph.img_terrain = mlx_xpm_file_to_image(game->graph.mlx, TERRAIN, &img_width, &img_height);
    game->graph.img_wall = mlx_xpm_file_to_image(game->graph.mlx, WALL, &img_width, &img_height);
    game->graph.img_player = mlx_xpm_file_to_image(game->graph.mlx, PLAYER, &img_width, &img_height);
    game->graph.img_player2 = mlx_xpm_file_to_image(game->graph.mlx, PLAYER2, &img_width, &img_height);
    game->graph.img_collect = mlx_xpm_file_to_image(game->graph.mlx, selected_collect, &img_width, &img_height);
    game->graph.img_exit1 = mlx_xpm_file_to_image(game->graph.mlx, EXIT1, &img_width, &img_height);
    game->graph.img_exit = mlx_xpm_file_to_image(game->graph.mlx,EXIT, &img_width, &img_height);
    game->graph.img_WON = mlx_xpm_file_to_image(game->graph.mlx,WON, &img_width, &img_height);
    game->graph.img_LOSE = mlx_xpm_file_to_image(game->graph.mlx,LOSE, &img_width, &img_height);
    game->graph.img_enemy = mlx_xpm_file_to_image(game->graph.mlx,ENEMY, &img_width, &img_height);
    game->graph.img_enemy2 = mlx_xpm_file_to_image(game->graph.mlx,ENEMY2, &img_width, &img_height);
    place_image(game);
    mlx_key_hook(game->graph.win, hook_manage, game);
    mlx_hook(game->graph.win, 17, 1L << 17, close_win, &game->graph);
    mlx_loop_hook(game->graph.mlx, update_enemy_animation, game);
    mlx_loop(game->graph.mlx);
}
