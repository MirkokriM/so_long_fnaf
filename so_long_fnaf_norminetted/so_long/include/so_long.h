/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/11 09:12:07 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <sys/time.h>
# include "../minilibx/mlx.h"
# include "../mini-libft/libft.h"
# include "../mini-libft/get_next_line/get_next_line.h"
# include "../mini-libft/ft_printf/ft_printf.h"

typedef struct s_vars {
	char	**map;
	int		line;
	int		column;
	int		player;
	int		index_collect;
	int		exit;
	int		exit_x;
	int		exit_y;
}	t_vars;

typedef struct s_graph {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_collect;
	void	*img_enemy;
	void	*img_enemy2;
	void	*img_player;
	void	*img_player2;
	void	*img_won;
	void	*img_lose;
	void	*img_exit;
	void	*img_exit1;
	int		index_move;
	void	*win_empty;
	void	*img_terrain;
}	t_graph;

typedef struct s_game {
	t_vars		*vars;
	t_graph		graph;
	int			countdown;
	int			x;
	int			y;
	int			map_i;
	int			map_j;
	int			x_arrow;
	int			y_arrow;
	double		enemy_animation_timer;
	int			enemy_frame;
	u_int64_t	time_count;
}	t_game;

# define TERRAIN "./assets/terrain.xpm"
# define WALL "./assets/wall.xpm"

# define PLAYER "./assets/player.xpm"
# define PLAYER2 "./assets/player2.xpm"

# define FRAMERATE 15
# define ANIMATIONDELAY 2000
# define CDOWN 60000

# define COLLECT "./assets/collect.xpm"
# define COLLECT2 "./assets/collect2.xpm"
# define COLLECT3 "./assets/collect3.xpm"
# define COLLECT4 "./assets/collect4.xpm"
# define COLLECT5 "./assets/collect5.xpm"

# define EXIT "./assets/exit.xpm"
# define EXIT1 "./assets/exit1.xpm"

# define ENEMY "./assets/enemy.xpm"
# define ENEMY2 "./assets/enemy2.xpm"

# define WON "./assets/WON.xpm"
# define LOSE "./assets/LOSE.xpm"

# define W 119
# define A 97
# define D 100
# define S 115
# define LEFT 65361
# define UP  65362
# define RIGHT 65363 
# define DOWN 65364
# define ESC 65307
# define TILESIZE 100

int			get_map(char *path, t_game *game);
int			count_line(char *path);
int			count_column(char *path);

void		update_exit(t_game *game, int map_i, int map_j);
void		exit_frame(t_game *game, int i, int j);
void		enemy_frame(t_game *game, int i, int j);

int			draw_time(t_game *game);
void		check_errors(t_game *game);
int			checks_vars(t_game *game);
int			checks_format(t_game *game);
void		error(t_game *game, int id);

void		draw_move(t_game *game);
void		free_vars(t_game *game);

u_int64_t	get_time(void);
void		mlx_manage(t_game *game);
int			close_win(t_graph *graph);
int			close_winning(t_graph *graph);
int			close_lose(t_graph *graph);

int			close_win(t_graph *graph);
int			close_winning(t_graph *graph);
int			close_lose(t_graph *graph);

void		place_image(t_game *game);
void		put_correct_image(t_game *game);

int			hook_manage(int keycode, t_game *game);

void		move_condition(t_game *game, int id);

void		direction_w(int id, t_game *game);
void		direction_s(int id, t_game *game);
void		direction_a(int id, t_game *game);
void		direction_d(int id, t_game *game);

char		*time_count_time(t_game *game);

#endif
