/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:56:53 by afavre            #+#    #+#             */
/*   Updated: 2022/12/14 10:24:52 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_libx(t_game *game, char *map_name)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.width = (game->map.width - 1) * 32;
	game->mlx.height = game->map.height * 32;
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr, \
		game->mlx.width, game->mlx.height, "So_Long");
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.mlx_win, \
		game->mlx.width / 2, game->mlx.height / 2, 0xFFFFFF, map_name);
}
