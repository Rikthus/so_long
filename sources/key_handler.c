/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:52:52 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/16 16:10:08 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_win(t_vars *vars)
{
	free_split(vars->map.world);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

void	mv_up(t_vars *vars)
{
	if (vars->map.world[vars->map.p_x - 1][vars->map.p_y] == 'E' &&
		vars->map.items == 0)
		put_player_img(vars, vars->map.p_x - 1, vars->map.p_y);
	else if (vars->map.world[vars->map.p_x - 1][vars->map.p_y] == '0')
		put_player_img(vars, vars->map.p_x - 1, vars->map.p_y);
	else if (vars->map.world[vars->map.p_x - 1][vars->map.p_y] == 'C')
	{
		put_player_img(vars, vars->map.p_x - 1, vars->map.p_y);
		vars->map.items--;
	}
	else if (vars->map.world[vars->map.p_x - 1][vars->map.p_y] == 'E')
		exit_win(vars);
}

void	mv_down(t_vars *vars)
{
	if (vars->map.world[vars->map.p_x - 1][vars->map.p_y] == 'E' &&
		vars->map.items == 0)
		put_player_img(vars, vars->map.p_x + 1, vars->map.p_y);
	else if (vars->map.world[vars->map.p_x + 1][vars->map.p_y] == '0')
		put_player_img(vars, vars->map.p_x + 1, vars->map.p_y);
	else if (vars->map.world[vars->map.p_x + 1][vars->map.p_y] == 'C')
	{
		put_player_img(vars, vars->map.p_x + 1, vars->map.p_y);
		vars->map.items--;
	}
	else if (vars->map.world[vars->map.p_x + 1][vars->map.p_y] == 'E')
		exit_win(vars);
}
void	mv_left(t_vars *vars)
{
	if (vars->map.world[vars->map.p_x][vars->map.p_y - 1] == 'E' &&
		vars->map.items == 0)
		put_player_img(vars, vars->map.p_x, vars->map.p_y - 1);
	else if (vars->map.world[vars->map.p_x][vars->map.p_y - 1] == '0')
		put_player_img(vars, vars->map.p_x, vars->map.p_y - 1);
	else if (vars->map.world[vars->map.p_x][vars->map.p_y - 1] == 'C')
	{
		put_player_img(vars, vars->map.p_x, vars->map.p_y - 1);
		vars->map.items--;
	}
	else if (vars->map.world[vars->map.p_x][vars->map.p_y - 1] == 'E')
		exit_win(vars);
}

void	mv_right(t_vars *vars)
{
	if (vars->map.world[vars->map.p_x][vars->map.p_y + 1] == 'E' &&
		vars->map.items == 0)
		put_player_img(vars, vars->map.p_x, vars->map.p_y + 1);
	else if (vars->map.world[vars->map.p_x][vars->map.p_y + 1] == '0')
		put_player_img(vars, vars->map.p_x, vars->map.p_y + 1);
	else if (vars->map.world[vars->map.p_x ][vars->map.p_y + 1] == 'C')
	{
		put_player_img(vars, vars->map.p_x, vars->map.p_y + 1);
		vars->map.items--;
	}
	else if (vars->map.world[vars->map.p_x][vars->map.p_y + 1] == 'E')
		exit_win(vars);
}
