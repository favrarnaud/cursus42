/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:26:52 by afavre            #+#    #+#             */
/*   Updated: 2022/12/27 07:00:50 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->data.pl_pos.x;
	y = game->data.pl_pos.y;
	mlx_put_image_to_window(game->mlx.mlx_ptr, \
		game->mlx.mlx_win, game->sprite.player, x * SIZE, y * SIZE);
}

void	get_player_pos(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < game->map.width - 1)
	{
		while (y < game->map.height)
		{
			if (game->map.map_tab[y][x] == 'P')
			{
				game->data.pl_pos.x = x;
				game->data.pl_pos.y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	init_game_data(t_game *game)
{
	game->data.coin_get = 0;
	game->check_data.nb_coin = 0;
	game->check_data.nb_player = 0;
	game->check_data.nb_exit = 0;
	game->data.move = 0;
	get_coin_amount(game);
	get_player_pos(game);
	draw_player(game);
}
