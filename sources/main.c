/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:11:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/16 19:09:57 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player_img(t_vars *vars, int x, int y)
{
	vars->data.img_bg = mlx_xpm_file_to_image(vars->mlx, "./assets/bg.xpm",
	&vars->data.img_width, &vars->data.img_heigth);
	if (!vars->data.img_bg)
	{
		free_split(vars->map.world);
		exit(0);
	}
	vars->data.addr = mlx_get_data_addr(vars->data.img_bg,
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
	vars->data.img_bg, vars->map.p_y * 64, vars->map.p_x * 64);
	vars->map.p_x = x;
	vars->map.p_x = y;
	vars->data.addr = mlx_get_data_addr(vars->data.img_player,
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
	vars->data.img_player, y * 64, x * 64);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_win(vars);
	else if (keycode == 13)
		mv_up(vars);
	else if (keycode == 1)
		mv_down(vars);
	else if (keycode == 0)
		mv_left(vars);
	else if (keycode == 2)
		mv_right(vars);
	return (1);
}

void	fill_win(t_vars *vars)
{
	if (!put_bg(vars) || !put_wall(vars) || !put_item(vars) || !put_player(vars))
	{
		free_split(vars->map.world);
		exit(0);
	}
	if (vars->map.items == 0 && !put_exit(vars))
	{
		free_split(vars->map.world);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || !parsing(argv, &vars))
	{
		ft_printf("Error\n");
		return (0);
	}
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	vars.mlx_win = mlx_new_window(vars.mlx, vars.map.width * 64,
	vars.map.height * 64, "so_fun");
	fill_win(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
