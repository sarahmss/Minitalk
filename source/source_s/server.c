/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:50 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/25 19:57:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void handler_sigusr(int sig)
{
    static char    c = 0xFF;
    static int     bits = 0;
    
    if (sig == SIGUSR1)
	{ 
        ft_printf("0", sig);
        c ^= 0x80 >> bits;
    }
   if (sig == SIGUSR2)
	{ 
        ft_printf("1", sig);
        c |= 0x80 >> bits;
    }
    bits++;
    if (bits == 8)
    {
        ft_printf("-> %c\n", c);
        bits = 0;
        c = 0xFF;
    }
}

int main(void)
{
    pid_t       pid;
    
    pid = getpid();
    ft_printf("PID: %d\n", pid);
    signal(SIGUSR1, handler_sigusr);
    signal(SIGUSR2, handler_sigusr);
    while (1)
        pause();
   return (0); 
}