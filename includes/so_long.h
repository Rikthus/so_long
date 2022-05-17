/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:20:30 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/17 11:36:04 by maxperei         ###   ########lyon.fr   */
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

typedef struct s_data
{
	int		img_width;
	int		img_heigth;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img_bg;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
	void	*img_wall;
}	t_data;


typedef struct s_map
{
	char	**world;
	int		height;
	int		width;
	int		items;
	int		exits;
	int		player;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_map	map;
}	t_vars;

// MAIN
int		key_hook(int keycode, t_vars *vars);
void	fill_win(t_vars *vars);
void	put_player_img(t_vars *vars, int x, int y);

// PARSING
int		parsing(char **argv, t_vars *vars);

// FILL_WIN
int		put_bg(t_vars *vars);
int		put_wall(t_vars *vars);
int		put_item(t_vars *vars);
int		put_player(t_vars *vars);
int		put_exit(t_vars *vars);

// KEY_HANDLER
void	exit_win(t_vars *vars);
void	mv_player(t_vars *vars, int x, int y);

// UTILS
char	*get_map(char *file);
void	free_split(char **split);
void	check_array(char **array);

#endif
