/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:27:16 by afavre            #+#    #+#             */
/*   Updated: 2022/12/19 14:10:55 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *filename)
{
	int		fd;
	char	*line;
	int		res;

	fd = open(filename, 'r');
	line = NULL;
	res = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			res++;
		else
			break ;
		free(line);
	}
	free(line);
	close(fd);
	return (res);
}

char	*map_to_str(t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	j = 0;
	k = 0;
	res = malloc(sizeof(char *) * (game->map.height * game->map.width) - 1);
	while (game->map.map_tab[i] != NULL)
	{
		while (game->map.map_tab[i][j] != '\0')
		{
			res[k] = game->map.map_tab[i][j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

void	put_line(char *line, int num_line, t_game *game)
{
	size_t	i;

	i = 0;
	game->map.map_tab[num_line] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (i < ft_strlen(line))
	{
		game->map.map_tab[num_line][i] = line[i];
		i++;
	}
	game->map.width = ft_strlen(line);
	game->map.map_tab[num_line][i] = '\0';
}

int	read_map(char *filename, t_game *game)
{
	int		nb_line;
	int		fd;
	char	*line;
	int		i;

	nb_line = count_line(filename);
	fd = open(filename, 'r');
	i = 0;
	game->map.map_tab = malloc(sizeof(char *) * nb_line + 1);
	game->map.height = nb_line;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			put_line(line, i, game);
		}
		else
			break ;
		free(line);
		i++;
	}
	free(line);
	game->map.map_tab[nb_line] = NULL;
	return (0);
}
