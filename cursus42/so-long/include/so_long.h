/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:47:03 by afavre            #+#    #+#             */
/*   Updated: 2022/12/27 07:03:26 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft/include/libft.h"
# include "../libft/gnl/include/get_next_line.h"
# include "../libft/printf/include/ft_printf.h"
# include "../miniLibX/mlx.h"
# include "KEY.h"

//taille des sprites
# define SIZE	32

typedef struct mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
}	t_mlx;

typedef struct map
{
	int			width;
	int			height;
	char		**map_tab;
	char		**copy_map;
}	t_map;

typedef struct sprite
{
	void		*wall;
	void		*floor;
	void		*exit;
	void		*coin;
	void		*player;
}	t_sprite;

typedef struct char_fill
{
	char		to_fill;
	char		to_put;
}	t_char_fill;

typedef struct check_utils
{
	int			nb_coin;
	int			nb_player;
	int			nb_exit;
}	t_check_utils;

typedef struct pos
{
	int			x;
	int			y;
}	t_pos;

typedef struct data
{
	t_pos		pl_pos;
	t_pos		new_pl_pos;
	int			coin_amount;
	int			coin_get;
	int			move;
}	t_data;

typedef struct game
{
	t_mlx			mlx;
	t_map			map;
	t_sprite		sprite;
	t_data			data;
	t_check_utils	check_data;
	t_char_fill		char_fill;
}	t_game;

// Event handler
int		key_handler(int key, void *param);
void	init_event(t_game *game);

//libx_handler
void	init_libx(t_game *lbx, char *map_name);

//Check file
int		check_file_valide(char *filename);
int		check_extension(char *filename);
int		check_data(char *filename);

//Error_handler
int		send_error(char *msg);

//map_handler
int		read_map(char *filename, t_game *game);
char	*map_to_str(t_game *game);

//check_map
int		check_map(t_game *game);

//sprite_handler
void	init_sprite(t_game *game);
void	draw_plate(t_game *game);

//data_handler
void	init_game_data(t_game *game);
void	draw_player(t_game *game);

//movement_handler
void	do_move_up(t_game *game);
void	do_move_down(t_game *game);
void	do_move_left(t_game *game);
void	do_move_right(t_game *game);

//utils
void	set_new_pose(t_game *game, char type);
void	clear_old_cell(t_game *game);
void	set_player(t_game *game, int x, int y);
void	get_coin_amount(t_game *game);
void	update_player(t_game *game);

//check_solve
int		check_solve(t_game *game);

//floodfill
int		fill_coin(char **tab, t_pos size, t_pos cur, t_game *game);
int		fill_exit(char **tab, t_pos size, t_pos cur, t_game *game);

//utils_map
char	**get_copy(t_game *game);

//utils2.c
void	va_chier(t_game *game);
void	clear_new_cell(t_game *game);
void	player_get_coin(t_game *game, int x, int y);

#endif