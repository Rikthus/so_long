/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:11:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/16 16:12:29 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player_img(t_vars *vars, int x, int y)
{
	mlx_destroy_image(vars->mlx, vars->player_img);
	vars->addr = mlx_get_data_addr(vars->player_img, &vars->bits_per_pixel,
								   &vars->line_lenght, &vars->endian);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->player_img, x * 64, y * 64);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 27)
		exit_win(vars);
	else if (keycode == 87)
		mv_up(vars);
	else if (keycode == 83)
		mv_down(vars);
	else if (keycode == 65)
		mv_left(vars);
	else if (keycode == 68)
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
