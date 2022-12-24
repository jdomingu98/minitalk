/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:35:50 by jdomingu          #+#    #+#             */
/*   Updated: 2022/08/14 11:51:59 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_reset(char buf[], int *bit, int *i)
{
	buf[*i] = 0;
	write(1, buf, *i);
	*i = 0;
	*bit = 0;
	ft_bzero(buf, 10001);
}

static void	handle_sigusr(int signum)
{
	static char	buf[10001];
	static int	bit;
	static int	i;

	if (--bit == -1)
	{
		bit = 6;
		i++;
	}
	if (i == 10000)
		ft_reset(buf, &bit, &i);
	buf[i] &= ~(1 << 7);
	if (signum == SIGUSR1)
		buf[i] |= (1 << bit);
	else if (signum == SIGUSR2)
		buf[i] |= (0 << bit);
	if (buf[i] == 127)
		ft_reset(buf, &bit, &i);
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		pause();
}
