/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulipe <tulipe@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:20:30 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/15 23:10:37 by tulipe           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	**world;
	int		height;
	int		width;
	int		items;
	int		exits;
	int		player;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*player_img;
	void	*img;
	int		img_width;
	int		img_height;
	t_map	map;
}	t_vars;

// PARSING
int		parsing(char **argv, t_vars *vars);

// FT_SPLIT_ME
char	**ft_split_me(char *str, char c);

// UTILS
char	*get_map(char *file);
void	free_split(char **split);
void	check_array(char **array);

#endif
