/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:08:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/18 12:02:27 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	char	*get_loop(int fd)
{
	static char		*actual = "\0";
	char			*past;
	char			*new;

	past = NULL;
	new = get_next_line(fd);
	if (!new)
		return (NULL);
	while (new)
	{
		if (actual[0] != '\0')
			past = actual;
		actual = ft_strjoin(actual, new);
		if (!actual)
		{
			free(new);
			return (NULL);
		}
		free(past);
		free(new);
		new = get_next_line(fd);
	}
	return (actual);
}

char	*get_map(char *file)
{
	int		fd;
	char	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = get_loop(fd);
	close(fd);
	return (map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	init_player_pos(t_map *map, int i, int j)
{
	map->p_x = i;
	map->p_y = j;
	map->player++;
}
