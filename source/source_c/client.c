/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/23 14:15:06 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(int argc, char *argv[])
{
    int pid;
    
    if (argc != 2)
	{
		ft_printf("Client: invalid arguments. Try ./client <pid> <str>\n");
		exit (0);
	}
    pid = ft_atoi(argv[1]);
    kill(pid, SIGUSR1);
    return (0);
}