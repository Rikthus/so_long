/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:02:09 by maxperei          #+#    #+#             */
/*   Updated: 2022/05/15 20:27:31 by maxperei         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	char	*ft_strdup_end(char *str, char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dup = malloc(sizeof(*dup) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static	int	count_words(char *str, char c)
{
	int		i;
	int		nb_words;
	char	previous_c;

	i = 0;
	nb_words = 0;
	previous_c = c;
	while (str[i])
	{
		if (str[i] != c && previous_c == c)
			nb_words++;
		previous_c = str[i];
		i++;
	}
	return (nb_words);
}

static	char	**ft_get_array(char **array, char *str, char c)
{
	int		i;
	int		j;
	char	prev_c;

	i = 0;
	j = 0;
	prev_c = c;
	array[0] = NULL;
	while (str[i])
	{
		if (prev_c == c && str[i] != c)
		{
			array[j] = ft_strdup_end(&str[i], c);
			if (!array[j])
			{
				free_split(array);
				return (0);
			}
			j++;
		}
		prev_c = str[i];
		i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split_me(char *str, char c)
{
	int		nb_words;
	char	**array;

	if (!str)
		return (NULL);
	ft_printf("ok_map\n");
	nb_words = count_words(str, c);
	if (nb_words < 1)
		return (NULL);
	array = malloc(sizeof(*array) * (nb_words + 1));
	if (!array)
		return (NULL);
	array = ft_get_array(array, str, c);
	return (array);
}
