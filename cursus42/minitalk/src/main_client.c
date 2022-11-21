/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:46:32 by afavre            #+#    #+#             */
/*   Updated: 2022/11/21 10:03:55 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if ((c >> (i - 1)) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

static void	ft_send_message(int pid, char *str)
{
	while (*str)
	{
		ft_send_char(pid, (unsigned char) *str);
		str++;
	}
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	int	srv_pid;

	(void)av;
	if (ac != 3)
	{
		ft_printf("Error : ./client {PID} {message}\n");
		return (0);
	}
	srv_pid = ft_atoi(av[1]);
	ft_send_message(srv_pid, av[2]);
	return (0);
}
