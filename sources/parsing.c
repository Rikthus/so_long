/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:18:33 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/14 20:00:27 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	check_f_format(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strcmp(&file[len - 4], ".ber") != 0)
		return (0);
	return (1);
}

static	char	*get_map(char *file)
{
	int				fd;
	static	char	*actual = "/0";
	static	char	*new = "/0";

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (new)
	{
		actual = ft_strjoin(actual, new);
		if (!actual)
		{
			free(new);
			return (NULL);
		}
		free(new);
		new = get_next_line(fd);
		if (!new)
		{
			free(actual);
			return (NULL);
		}
	}
	close(fd);
	return (actual);
}

int	rectangle_map(t_vars *vars)
{
	int	l_size;
	int	i;

	l_size = ft_strlen(vars->map.world[0]);
	i = 0;
	while (vars->map.world[i])
	{
		if (ft_strlen(vars->map.world[i] != l_size))
			return (0);
		i++;
	}
	if (l_size < 3 || i < 3)
		return (0);
	vars->map.height = i;
	vars->map.width = l_size;
	return (1);
}

int	position()
{
	
}

int	parsing(char **argv, t_vars *vars)
{
	if (check_f_format(argv[1]) == 0)
		return (0);
	vars->map.world = ft_split(get_map(argv[1]), '/n');
	if (!(vars->map.width))
		return (0);
	if (!rectangle_map(vars) || !position(vars))
	{
		free_split(vars->map.world);
		return (0);
	}
	return (1);
}
