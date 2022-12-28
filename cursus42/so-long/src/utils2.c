/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:17:28 by afavre            #+#    #+#             */
/*   Updated: 2022/12/27 07:03:22 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	va_chier(t_game *game)
{
	game->data.move++;
	ft_printf("Vous avez effectué %d pas !\n", game->data.move);
	update_player(game);
}

void	clear_new_cell(t_game *game)
{
	int	x;
	int	y;

	x = game->data.new_pl_pos.x;
	y = game->data.new_pl_pos.y;
	mlx_put_image_to_window(game->mlx.mlx_ptr, \
		game->mlx.mlx_win, game->sprite.floor, x * SIZE, y * SIZE);
}

void	player_get_coin(t_game *game, int x, int y)
{
	game->data.coin_get++;
	clear_new_cell(game);
	game->map.map_tab[y][x] = '0';
}
