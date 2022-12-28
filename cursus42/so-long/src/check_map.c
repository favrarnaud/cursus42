/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:14:51 by afavre            #+#    #+#             */
/*   Updated: 2022/12/19 14:11:24 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_doublon(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	str = map_to_str(game);
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			game->check_data.nb_coin++;
		else if (str[i] == 'P')
			game->check_data.nb_player++;
		else if (str[i] == 'E')
			game->check_data.nb_exit++;
		i++;
	}
	if (game->check_data.nb_coin < 0
		|| game->check_data.nb_player != 1
		|| game->check_data.nb_exit != 1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	check_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map_tab[i] != NULL)
	{
		while (game->map.map_tab[i][j] != '\0')
		{
			if (game->map.map_tab[i][j] != '0'
				&& game->map.map_tab[i][j] != '1'
				&& game->map.map_tab[i][j] != 'C'
				&& game->map.map_tab[i][j] != 'P'
				&& game->map.map_tab[i][j] != 'E'
				&& game->map.map_tab[i][j] != '\n'
				&& game->map.map_tab[i][j] != '\0')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map_tab[i] != NULL && i < game->map.height)
	{
		while (game->map.map_tab[i][j] != '\0' && j < game->map.width - 1)
		{
			if (i == 0 || i == game->map.height - 1)
			{
				if (game->map.map_tab[i][j] != '1')
					return (-1);
			}
			else if (j == 0 || j == game->map.width - 2)
			{
				if (game->map.map_tab[i][j] != '1')
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_form(t_game *game)
{
	int		i;
	size_t	dif;

	i = 0;
	dif = 0;
	while (game->map.map_tab[i] != NULL)
	{
		if (i == 0)
			dif = ft_strlen(game->map.map_tab[i]);
		else
		{
			if (ft_strlen(game->map.map_tab[i]) != dif)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	if (check_doublon(game) != 0)
		return (send_error("Elements incorrect !"));
	else if (check_content(game) != 0)
		return (send_error("Charactere inexsistant dans la map"));
	else if (check_wall(game) != 0)
		return (send_error("trous dans les murs de la map"));
	else if (check_form(game) != 0)
		return (send_error("la map n'est pas rectangulaire"));
	return (0);
}
