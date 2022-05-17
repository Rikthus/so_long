/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:52:52 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/17 13:10:51 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_win(t_vars *vars)
{
	free_split(vars->map.world);
	mlx_destroy_image(vars->mlx, vars->data.img_bg);
	mlx_destroy_image(vars->mlx, vars->data.img_player);
	mlx_destroy_image(vars->mlx, vars->data.img_exit);
	mlx_destroy_image(vars->mlx, vars->data.img_item);
	mlx_destroy_image(vars->mlx, vars->data.img_wall);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

void	mv_player(t_vars *vars, int x, int y)
{
	if (vars->map.world[x][y] == '1')
		return ;
	else if (vars->map.world[x][y] == 'C')
	{
		put_player_img(vars, x, y);
		vars->map.world[x][y] = '0';
		vars->map.items--;
		if (vars->map.items == 0)
			put_exit(vars);
	}
	else if (vars->map.world[x][y] == 'E' && vars->map.items == 0)
	{
		put_player_img(vars, x, y);
		exit_win(vars);
	}
	else
		put_player_img(vars, x, y);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_win(vars);
	else if (keycode == 13)
		mv_player(vars, vars->map.p_x - 1, vars->map.p_y);
	else if (keycode == 1)
		mv_player(vars, vars->map.p_x + 1, vars->map.p_y);
	else if (keycode == 0)
		mv_player(vars, vars->map.p_x, vars->map.p_y - 1);
	else if (keycode == 2)
		mv_player(vars, vars->map.p_x, vars->map.p_y + 1);
	return (1);
}
