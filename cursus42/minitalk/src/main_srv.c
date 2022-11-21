/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_srv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:39 by afavre            #+#    #+#             */
/*   Updated: 2022/11/21 09:44:16 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bin_to_char(char *str)
{
	int	i;
	int	rem;
	int	res;

	i = 0;
	rem = 128;
	res = 0;
	while (str[i])
	{
		if (str[i] == '1')
			res += rem;
		i++;
		rem /= 2;
	}
	return (res);
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	*str;

	(void)ucontext;
	(void)info;
	if (str == NULL)
		str = malloc(sizeof(char) * 8);
	else
		i += 1;
	if (i <= 7)
	{
		if (sig == 30)
			str[i] = '0';
		else
			str[i] = '1';
	}
	if (i == 7)
	{
		ft_printf("%c", bin_to_char(str));
		i = 0;
		free(str);
		str = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server started at %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
