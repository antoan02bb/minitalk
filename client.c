/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:43 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/14 19:03:56 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"


/**
 * @brief 	convert the character(from the message in the command line arguments) into 8 bits and send each bit as a signal to the server
 * @param 	pid the proces ID pf the
 * @details client waits 42 microseconds - te elay alows the server to process the received signal
 */
void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i; // ex: from 01100001 -> to 00000001 (which means 1)
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2); // SIGUSR2 to represent a 0 bit
		else
			kill(pid, SIGUSR1); // SIGUSR1 to represent a 1 bit
		
		usleep(42);
	}
}

// 1. read the server's pid and the message from the command line
/**
 * @param argv[0] - program name
 * @param argv[1] - server pid
 * @param argv[2] - message printed
 */
int	main(int argc, char **argv)
{
	pid_t client_id;
	char *str_to_send;
	int i;
	
	if (argc == 3)
	{
		client_id = ft_atoi(argv[1]);
		str_to_send = argv[2];
		
		i = 0;
		while (str_to_send[i])
		{
			// for each character call 'send_signal'
			send_signal(client_id, (unsigned char)str_to_send[i]);
			i++;
		}
	send_signal(client_id, '\0');
	}
	else
		return(ft_printf("Wrong number of arguments!\n"), 1);
	return (0);
}