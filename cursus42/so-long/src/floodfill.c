/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:44:25 by afavre            #+#    #+#             */
/*   Updated: 2022/12/16 10:37:21 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_coin(char **tab, t_pos size, t_pos cur, t_game *game)
{
	static int	res_coin;

	if (tab[cur.y][cur.x] == 'C')
	{
		tab[cur.y][cur.x] = '0';
		res_coin++;
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != game->char_fill.to_fill)
		return (-1);
	tab[cur.y][cur.x] = game->char_fill.to_put;
	fill_coin(tab, size, (t_pos){cur.x - 1, cur.y}, game);
	fill_coin(tab, size, (t_pos){cur.x + 1, cur.y}, game);
	fill_coin(tab, size, (t_pos){cur.x, cur.y - 1}, game);
	fill_coin(tab, size, (t_pos){cur.x, cur.y + 1}, game);
	return (res_coin);
}

int	fill_exit(char **tab, t_pos size, t_pos cur, t_game *game)
{
	static int	res_exit;

	if (tab[cur.y][cur.x] == 'E')
	{
		tab[cur.y][cur.x] = 'F';
		res_exit++;
	}
	if (tab[cur.y][cur.x] == 'C')
		tab[cur.y][cur.x] = '0';
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != game->char_fill.to_fill)
		return (-1);
	tab[cur.y][cur.x] = game->char_fill.to_put;
	fill_exit(tab, size, (t_pos){cur.x - 1, cur.y}, game);
	fill_exit(tab, size, (t_pos){cur.x + 1, cur.y}, game);
	fill_exit(tab, size, (t_pos){cur.x, cur.y - 1}, game);
	fill_exit(tab, size, (t_pos){cur.x, cur.y + 1}, game);
	return (res_exit);
}
