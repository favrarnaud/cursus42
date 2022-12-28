/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:50:17 by afavre            #+#    #+#             */
/*   Updated: 2022/12/16 10:14:14 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key, void *param)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W || key == KEY_UP)
		do_move_up(param);
	if (key == KEY_A || key == KEY_LEFT)
		do_move_left(param);
	if (key == KEY_S || key == KEY_DOWN)
		do_move_down(param);
	if (key == KEY_D || key == KEY_RIGHT)
		do_move_right(param);
	return (0);
}

int	close_game(void)
{
	exit(0);
	return (0);
}

void	init_event(t_game *game)
{
	mlx_hook(game->mlx.mlx_win, 17, 0, close_game, NULL);
	mlx_key_hook(game->mlx.mlx_win, key_handler, game);
}
