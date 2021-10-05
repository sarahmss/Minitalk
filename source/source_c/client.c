/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/04 21:48:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	sucess(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Data has been received\n", 24);
		exit (0);
	}
}

static void	send_signals(int pid, unsigned int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c % 2 == 0 || c == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (1);
		}
		else if (kill(pid, SIGUSR2) == -1)
			exit (1);
		usleep(800);
		c /= 2;
		bits++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = sucess;
	if (argc != 3)
	{
		write(1, "Client: invalid arguments. Try ./client <pid> <\"str\">", 54);
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_signals(pid, *message);
		message++;
	}
	sigaction(SIGUSR2, &sa, NULL);
	send_signals(pid, '\0');
	return (0);
}
