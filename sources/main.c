/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:11:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/15 18:26:38 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || !parsing(argv, &vars))
	{
		ft_printf("Error\n");
		return (0);
	}
	//vars.mlx = mlx_init();
	//vars.mlx_win = mlx_new_window(vars.mlx, xxx, yyy, "so_long");
	//mlx_loop(vars.mlx);
	return (0);
}
