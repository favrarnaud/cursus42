/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:09:33 by afavre            #+#    #+#             */
/*   Updated: 2022/12/16 10:09:53 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_copy(t_game *game)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * game->map.height + 1);
	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		res[i] = malloc (sizeof(char) * game->map.width + 1);
		while (j < game->map.width - 1)
		{
			res[i][j] = game->map.map_tab[i][j];
			j++;
		}
		res[i][j] = '\0';
		j = 0;
		i++;
	}
	res[i] = NULL;
	return (res);
}
