/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:08:38 by afavre            #+#    #+#             */
/*   Updated: 2022/12/16 10:22:06 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.copy_map[i] != NULL)
	{
		free(game->map.copy_map[i]);
		i++;
	}
	free(game->map.copy_map);
}

int	check_coin(t_game *game)
{
	t_pos	size_map;
	int		hit_coin;

	size_map.x = game->map.width;
	size_map.y = game->map.height;
	hit_coin = fill_coin(game->map.copy_map, size_map, \
		game->data.pl_pos, game);
	if (hit_coin == game->data.coin_amount)
		return (1);
	return (0);
}

int	check_exit(t_game *game)
{
	t_pos	size_map;
	int		hit_exit;

	size_map.x = game->map.width;
	size_map.y = game->map.height;
	hit_exit = fill_exit(game->map.copy_map, \
		size_map, game->data.pl_pos, game);
	if (hit_exit == 1)
		return (1);
	return (0);
}

int	check_solve(t_game *game)
{
	game->map.copy_map = get_copy(game);
	game->map.copy_map[game->data.pl_pos.y][game->data.pl_pos.x] = '0';
	game->char_fill.to_fill = '0';
	game->char_fill.to_put = 'F';
	if (check_coin(game) == 0)
		return (send_error("Certains coins ne sont pas accessible !"));
	clear_map(game);
	game->map.copy_map = get_copy(game);
	game->map.copy_map[game->data.pl_pos.y][game->data.pl_pos.x] = '0';
	if (check_exit(game) == 0)
		return (send_error("La sortie n'est pas accessible !"));
	clear_map(game);
	return (0);
}
