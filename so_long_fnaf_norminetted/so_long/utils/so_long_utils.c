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

u_int64_t	get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t)(1000)) + (time.tv_usec / 1000));
}

char	*time_count_time(t_game *game)
{
	u_int64_t	start;
	char		*res;

	start = (game->countdown * 1000 - (get_time() - game->time_count)) / 1000;
	if (start <= 0)
		close_lose(&(game->graph));
	res = ft_itoa(start);
	return (res);
}

int	draw_time(t_game *game)
{
	char	*time;
	char	*time_str;

	if (game->time_count)
	{
		time = time_count_time(game);
		time_str = ft_strjoin("C.down: ", time);
		mlx_set_font(game->graph.mlx, game->graph.win, "8x13bold");
		mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
			game->graph.img_wall, (game->vars->column * TILESIZE) \
				- TILESIZE, 0);
		mlx_string_put(game->graph.mlx, game->graph.win, \
			(game->vars->column * TILESIZE) - 90, 20, \
				0xFFFFFF, time_str);
		free(time);
		free(time_str);
	}	
	return (0);
}
