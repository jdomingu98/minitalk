/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:50:10 by jdomingu          #+#    #+#             */
/*   Updated: 2022/08/14 11:51:29 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(int server_pid, char c)
{
	int	bshift;

	bshift = 6;
	while (bshift >= 0)
	{
		if (c & (1 << bshift))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bshift--;
		usleep(100);
	}
}

static void	ft_send_str(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(server_pid, str[i]);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		kill(server_pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		exit(EXIT_FAILURE);
	ft_send_str(ft_atoi(av[1]), av[2]);
	exit(EXIT_SUCCESS);
}
