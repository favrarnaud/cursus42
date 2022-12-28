/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 06:58:53 by afavre            #+#    #+#             */
/*   Updated: 2022/12/14 16:38:33 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	n;

	n = ft_strlen(filename) - 4;
	if (ft_strncmp(&filename[n], ".ber", 4) != 0)
		return (-1);
	return (0);
}

int	check_file_valide(char *filename)
{
	int	fd;

	fd = open(filename, 'r');
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_data(char *filename)
{
	int		res;

	res = 0;
	if (check_extension(filename) != 0)
		return (send_error("Extension de fichier incorect"));
	if (check_file_valide(filename) != 0)
		return (send_error("Fichier introuvable"));
	return (0);
}
