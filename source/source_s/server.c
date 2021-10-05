/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:50 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/04 19:37:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	handler_sigusr(int sig, siginfo_t *info_signal, void *context)
{
	static unsigned int	caracter;
	static unsigned int	bits;

	(void)context;
	if (sig == SIGUSR2)
		caracter += 1 << bits;
	bits++;
	if (bits == 8)
	{
		if (caracter == 0)
		{
			write(1, "\n", 1);
			kill(info_signal->si_pid, SIGUSR2);
		}
		else
			write(1, &caracter, 1);
		bits = 0;
		caracter = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_sigusr;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
