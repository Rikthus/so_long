/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:36 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/18 11:56:22 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_bg(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->data.img_bg = mlx_xpm_file_to_image(vars->mlx, "./assets/bg.xpm",
			&(vars->data.img_width), &(vars->data.img_heigth));
	if (!vars->data.img_bg)
		return (0);
	vars->data.addr = mlx_get_data_addr(vars->data.img_bg,
			&vars->data.bits_per_pixel, &vars->data.line_length,
			&vars->data.endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == '0' || vars->map.world[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->data.img_bg, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->data.img_wall = mlx_xpm_file_to_image(vars->mlx, "./assets/wall.xpm",
			&(vars->data.img_width), &(vars->data.img_heigth));
	if (!vars->data.img_wall)
		return (0);
	vars->data.addr = mlx_get_data_addr(vars->data.img_wall,
			&vars->data.bits_per_pixel, &vars->data.line_length,
			&vars->data.endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->data.img_wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_item(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->data.img_item = mlx_xpm_file_to_image(vars->mlx, "./assets/item.xpm",
			&(vars->data.img_width), &(vars->data.img_heigth));
	if (!vars->data.img_item)
		return (0);
	vars->data.addr = mlx_get_data_addr(vars->data.img_item,
			&vars->data.bits_per_pixel, &vars->data.line_length,
			&vars->data.endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->data.img_item, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->data.img_player = mlx_xpm_file_to_image(vars->mlx,
			"./assets/player.xpm", &(vars->data.img_width),
			&(vars->data.img_heigth));
	if (!vars->data.img_player)
		return (0);
	vars->data.addr = mlx_get_data_addr(vars->data.img_player,
			&vars->data.bits_per_pixel, &vars->data.line_length,
			&vars->data.endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->data.img_player, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->data.img_exit = mlx_xpm_file_to_image(vars->mlx, "./assets/exit.xpm",
			&(vars->data.img_width), &(vars->data.img_heigth));
	if (!vars->data.img_exit)
		return (0);
	vars->data.addr = mlx_get_data_addr(vars->data.img_exit,
			&vars->data.bits_per_pixel, &vars->data.line_length,
			&vars->data.endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->data.img_exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}
