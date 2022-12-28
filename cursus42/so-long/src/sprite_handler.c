/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:42:52 by afavre            #+#    #+#             */
/*   Updated: 2022/12/14 09:05:40 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game)
{
	int	size;

	size = SIZE;
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"sprite/wall.xpm", &size, &size);
	game->sprite.floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"sprite/floor.xpm", &size, &size);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"sprite/exit.xpm", &size, &size);
	game->sprite.coin = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"sprite/coin.xpm", &size, &size);
	game->sprite.player = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		"sprite/player.xpm", &size, &size);
}

void	print_tile(t_game *game, char type, int x, int y)
{
	if (type == '1')
		mlx_put_image_to_window(game->mlx.mlx_ptr, \
			game->mlx.mlx_win, game->sprite.wall, x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(game->mlx.mlx_ptr, \
			game->mlx.mlx_win, game->sprite.floor, x * SIZE, y * SIZE);
	if (type == 'E')
		mlx_put_image_to_window(game->mlx.mlx_ptr, \
			game->mlx.mlx_win, game->sprite.exit, x * SIZE, y * SIZE);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx.mlx_ptr, \
			game->mlx.mlx_win, game->sprite.coin, x * SIZE, y * SIZE);
}

void	draw_plate(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map.width - 1)
	{
		while (y < game->map.height)
		{
			print_tile(game, game->map.map_tab[y][x], x, y);
			y++;
		}
		y = 0;
		x++;
	}
}
