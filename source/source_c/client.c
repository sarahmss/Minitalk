/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/25 19:55:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void send_signals(int pid, char *message)
{
    int bitshift;
    int i;
    int max;
    
    i = 0;
    bitshift = -1;
    max = 0x80;
    while(message[i])
    {
        while(++bitshift < 8)
        {
            if (message[i] & max >> bitshift)
            {
                if (kill(pid, SIGUSR2) == -1)
                    exit(1);                 
            }
            else
            {
                if(kill(pid, SIGUSR1) == -1)
                    exit(1);                 
            }
            usleep(3);
        }
        i++;
        bitshift = -1;
        max = 0x80;
    }

}

static void sucess(int sig)
{
    ft_printf("Data has been received with signal %d\n", sig);
}
int main(int argc, char *argv[])
{
    int     pid;
    
    if (argc != 3)
	{
		ft_printf("Client: invalid arguments. Try ./client <pid> <\"str>\"\n");
		exit (1);
	}
    pid = ft_atoi(argv[1]);
    send_signals(pid, argv[2]);
    signal(SIGUSR1, sucess);
    return (0);
}