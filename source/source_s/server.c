/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:50 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/29 11:28:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void handler_sigusr(int sig, siginfo_t *info_signal, void *context)
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
			printf("\n");
			kill(info_signal->si_pid, SIGUSR2);
		}
		else
			printf("%c", caracter);
		bits = 0;
		caracter = 0;
	}
}


int main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_sigusr;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
