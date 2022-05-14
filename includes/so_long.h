/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:20:30 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/14 17:57:30 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	**world;
	int		height;
	int		width;
	int		items;
	int		player;
}	t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*player_img;
	void	*img;
	int		img_width;
	int		img_length;
	t_map	map;
}	t_vars;

#endif
