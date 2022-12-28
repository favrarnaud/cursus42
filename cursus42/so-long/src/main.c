/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:26:09 by afavre            #+#    #+#             */
/*   Updated: 2022/12/27 07:00:25 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ac != 2)
		ft_printf("Error\nUtilisation : ./so_long [maps]\n");
	else
	{
		if (check_data(av[1]) != 0)
			exit(1);
		read_map(av[1], game);
		if (check_map(game) != 0)
			exit(1);
		init_libx(game, av[1]);
		init_sprite(game);
		draw_plate(game);
		init_game_data(game);
		if (check_solve(game) == -1)
			exit(1);
		init_event(game);
		mlx_loop(game->mlx.mlx_ptr);
	}
	free(game);
	return (0);
}
