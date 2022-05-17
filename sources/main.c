/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:11:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/17 14:38:17 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player_img(t_vars *vars, int x, int y)
{
	vars->map.nb_mv++;
	ft_printf("Moves: %d\n", vars->map.nb_mv);
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
	vars->map.p_y = y;
	vars->data.addr = mlx_get_data_addr(vars->data.img_player,
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
	vars->data.img_player, y * 64, x * 64);
}

void	fill_win(t_vars *vars)
{
	if (!put_bg(vars) || !put_wall(vars) || !put_item(vars) || !put_player(vars))
	{
		ft_printf("Error\nNo asset\n");
		free_split(vars->map.world);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.map.player = 0;
	vars.map.items = 0;
	vars.map.exits = 0;
	vars.map.nb_mv = 0;
	if (argc != 2 || !parsing(argv, &vars))
		return (0);
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
