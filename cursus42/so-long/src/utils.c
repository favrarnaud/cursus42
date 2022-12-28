/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:19:38 by afavre            #+#    #+#             */
/*   Updated: 2022/12/27 07:03:11 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_new_pose(t_game *game, char type)
{
	game->data.new_pl_pos.x = game->data.pl_pos.x;
	game->data.new_pl_pos.y = game->data.pl_pos.y;
	if (type == 'u')
		game->data.new_pl_pos.y--;
	else if (type == 'd')
		game->data.new_pl_pos.y++;
	else if (type == 'l')
		game->data.new_pl_pos.x--;
	else if (type == 'r')
		game->data.new_pl_pos.x++;
}

void	clear_old_cell(t_game *game)
{
	int	x;
	int	y;

	x = game->data.pl_pos.x;
	y = game->data.pl_pos.y;
	mlx_put_image_to_window(game->mlx.mlx_ptr, \
		game->mlx.mlx_win, game->sprite.floor, x * SIZE, y * SIZE);
}

void	get_coin_amount(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->data.coin_amount = 0;
	while (x < game->map.width)
	{
		while (y < game->map.height)
		{
			if (game->map.map_tab[y][x] == 'C')
				game->data.coin_amount++;
			y++;
		}
		y = 0;
		x++;
	}
}

void	update_player(t_game *game)
{
	clear_old_cell(game);
	game->data.pl_pos.x = game->data.new_pl_pos.x;
	game->data.pl_pos.y = game->data.new_pl_pos.y;
	draw_player(game);
}

void	set_player(t_game *game, int x, int y)
{
	int	stat;

	stat = 0;
	if (game->map.map_tab[y][x] != '1')
	{
		if (game->map.map_tab[y][x] == 'C')
			player_get_coin(game, x, y);
		else if (game->map.map_tab[y][x] == 'E')
		{
			if (game->data.coin_amount == game->data.coin_get)
			{
				ft_printf("Vous avez terminer le jeu en %d mouvements", \
					game->data.move + 1);
				exit(0);
			}
			else
				stat = 1;
		}
		if (stat == 0)
			va_chier(game);
		stat = 0;
	}
}
