/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:32:28 by afavre            #+#    #+#             */
/*   Updated: 2022/12/19 14:03:55 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_move_up(t_game *game)
{
	int	x;
	int	y;

	set_new_pose(game, 'u');
	x = game->data.new_pl_pos.x;
	y = game->data.new_pl_pos.y;
	set_player(game, x, y);
}

void	do_move_down(t_game *game)
{
	int	x;
	int	y;

	set_new_pose(game, 'd');
	x = game->data.new_pl_pos.x;
	y = game->data.new_pl_pos.y;
	set_player(game, x, y);
}

void	do_move_left(t_game *game)
{
	int	x;
	int	y;

	set_new_pose(game, 'l');
	x = game->data.new_pl_pos.x;
	y = game->data.new_pl_pos.y;
	set_player(game, x, y);
}

void	do_move_right(t_game *game)
{
	int	x;
	int	y;

	set_new_pose(game, 'r');
	x = game->data.new_pl_pos.x;
	y = game->data.new_pl_pos.y;
	set_player(game, x, y);
}
