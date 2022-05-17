/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:18:33 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/17 14:38:48 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	check_f_format(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strcmp(&file[len - 4], ".ber") == 0 && len > 4)
		return (1);
	return (0);
}

static	int	rectangle_map(t_vars *vars)
{
	int	l_size;
	int	i;

	l_size = ft_strlen(vars->map.world[0]);
	i = 0;
	while (vars->map.world[i])
	{
		if (ft_strlen(vars->map.world[i]) != (size_t)l_size)
			return (0);
		i++;
	}
	if (l_size < 3 || i < 3)
		return (0);
	vars->map.height = i;
	vars->map.width = l_size;
	return (1);
}

static	int	position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->world[i])
	{
		j = 0;
		while (map->world[i][j])
		{
			if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
				&& map->world[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int	components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->world[i])
	{
		j = 0;
		while (map->world[i][j])
		{
			if (map->world[i][j] == 'P')
			{
				map->p_x = i;
				map->p_y = j;
				map->player++;
			}
			else if (map->world[i][j] == 'C')
				map->items++;
			else if (map->world[i][j] == 'E')
				map->exits++;
			else if (map->world[i][j] != '1' && map->world[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->items < 1 || map->exits < 1)
		return (0);
	return (1);
}

int	parsing(char **argv, t_vars *vars)
{
	char	*map;

	if (check_f_format(argv[1]) == 0)
	{
		ft_printf("Error\nBad map file\n");
		return (0);
	}
	map = get_map(argv[1]);
	if (!map)
	{
		ft_printf("Error\nFile not found\n");
		return (0);
	}
	vars->map.world = ft_split(map, '\n');
	free(map);
	if (!(vars->map.world))
		return (0);
	if (!rectangle_map(vars) || !components(&vars->map) || !position(&vars->map))
	{
		free_split(vars->map.world);
		ft_printf("Error\nBad map format\n");
		return (0);
	}
	return (1);
}
