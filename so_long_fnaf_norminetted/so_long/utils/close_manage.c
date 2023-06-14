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

#include "../include/so_long.h"

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
	ft_printf("Move Counter: %d\n", graph->index_move + 1);
	exit(0);
}

int	close_lose(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
	free(graph->mlx);
	ft_printf("U DEAD! XDXD\n");
	ft_printf("Move Counter: %d\n", graph->index_move + 1);
	exit(0);
}

void	update_exit(t_game *game, int map_i, int map_j)
{
	game->vars->exit++;
	game->vars->exit_x = map_j;
	game->vars->exit_y = map_i;
}

// void final_frame(t_game *game)
// {
	
// }