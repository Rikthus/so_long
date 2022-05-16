/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:21:36 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/16 15:59:50 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_bg(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./assets/bg.xpm",
									  &(vars->img_width), &(vars->img_height));
	if (!vars->img)
		return (0);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_lenght, &vars->endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, j * 64, i * 64);
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
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./assets/wall.xpm",
	&(vars->img_width), &(vars->img_height));
	if (!vars->img)
		return (0);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_lenght, &vars->endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, j * 64, i * 64);
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
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./assets/item.xpm",
	&(vars->img_width), &(vars->img_height));
	if (!vars->img)
		return (0);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_lenght, &vars->endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, j * 64, i * 64);
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
	vars->player_img = mlx_xpm_file_to_image(vars->mlx, "./assets/player.xpm",
	&(vars->img_width), &(vars->img_height));
	if (!vars->img)
		return (0);
	vars->addr = mlx_get_data_addr(vars->player_img, &vars->bits_per_pixel,
									&vars->line_lenght, &vars->endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player_img, j * 64, i * 64);
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
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./assets/exit.xpm",
	&(vars->img_width), &(vars->img_height));
	if (!vars->img)
		return (0);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
									&vars->line_lenght, &vars->endian);
	while (vars->map.world[i])
	{
		j = 0;
		while (vars->map.world[i][j])
		{
			if (vars->map.world[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (1);
}

