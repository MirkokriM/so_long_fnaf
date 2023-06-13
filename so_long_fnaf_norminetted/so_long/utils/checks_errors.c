/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/07 20:09:51 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void error(t_game *game, int id)
{
	printf("Error\n");
	if (id == 1)
		ft_printf("Edges not valid\n");
	else if (id == 2)
		ft_printf("Found invalid character\n");
	else if (id == 3)
		ft_printf("Number of variables invalid\n");
	else if (id == 4)
		ft_printf("Lines/Columns format invalid\n");
	free_vars(game);
	exit(0);
}

int	checks_format(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->vars->line)
	{
		j = 0;
		while (game->vars->map[i][j])
		{
			j++;
		}
		if (j != game->vars->column + 1){
			
			return (1);

		}
		i++;
	}
	return (0);
}

int checks_vars(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->vars->line)
	{
		j= 0;
		while (j < game->vars->column)
		{
			if (game->vars->map[i][j] == 'P')
				game->vars->player++;
			else if (game->vars->map[i][j] == 'C')
				game->vars->index_collect++;
			if (game->vars->map[i][j] == 'E')
				game->vars->exit++;
			j++;
		}
		i++;
	}
	if (game->vars->player < 1 || game->vars-> index_collect < 1 || game->vars->exit < 1 ||
		game->vars->player > 1 || game->vars-> exit > 1)
		return (1);
	return (0);
}

void check_errors(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->vars->line)
	{
		j= 0;
		while (j < game->vars->column)
		{
			if ((game->vars->map[0][j] != '1' || game->vars->map[game->vars->line - 1][j] != '1') ||
				(game->vars->map[i][0] != '1' || game->vars->map[i][game->vars->column - 1] != '1'))
					error(game, 1);
			if (game->vars->map[i][j] != '0' && game->vars->map[i][j] != '1' && game->vars->map[i][j] != 'C' && 
				game->vars->map[i][j] != 'E' && game->vars->map[i][j] != 'P' && game->vars->map[i][j] != 'G' )
					error(game, 2);
			j++;
		}
		i++;
	}
	if (checks_vars(game) == 1)
		error(game, 3);
	if (checks_format(game) == 1)
		error(game, 4);
}
