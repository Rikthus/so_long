/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:08:56 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/15 23:11:41 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	char	*get_loop(int fd)
{
	char	*actual = "\0";
	char	*new;

	new = get_next_line(fd);
	if (!new)
		return (NULL);
	while (new)
	{
		actual = ft_strjoin(actual, new);
		if (!actual)
		{
			free(new);
			return (NULL);
		}
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

void	check_array(char **array)
{
	int i = 0;
	int j;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
