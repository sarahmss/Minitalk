/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:50 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/23 14:17:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void handler_sigusr1(int sig)
{
	ft_printf("signal %d received.\n", sig);
}

int main(void)
{
    pid_t   pid;

    pid = getpid();
    ft_printf("PID: %d\n", pid);
    signal(SIGUSR1, handler_sigusr1);
    while (1)
        pause();
   return (0); 
}