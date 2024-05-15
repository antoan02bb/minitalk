/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 05:36:26 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/15 18:15:25 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	receive_ack(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\033[1;31mA");
	ft_printf("\033[1;32mC");
	ft_printf("\033[1;33mK");
	ft_printf("\033[1;34mN");
	ft_printf("\033[1;35mO");
	ft_printf("\033[1;36mW");
	ft_printf("\033[1;37mL");
	ft_printf("\033[1;36mE");
	ft_printf("\033[1;35mD");
	ft_printf("\033[1;34mG");
	ft_printf("\033[1;33mE");
	ft_printf("\033[1;32mD");
	ft_printf("\033[1;31m!\n");
}

/**
 * @note SIGUSR1 to represent a 1 bit
 * @note SIGUSR2 to represent a 0 bit
 * @details temp_char = character >> i; // ex: from 01100001
	-> to 00000001 (which means 1)
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
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

/**
 * @param argv[0] - program name
 * @param argv[1] - server pid
 * @param argv[2] - message printed
 * @brief for each character of the message, send a signal to the server
 */
int	main(int argc, char **argv)
{
	pid_t	client_id;
	char	*str_to_send;
	int		i;

	if (argc == 3)
	{
		client_id = ft_atoi(argv[1]);
		str_to_send = argv[2];
		i = 0;
		while (str_to_send[i])
		{
			send_signal(client_id, (unsigned char)str_to_send[i]);
			i++;
		}
		signal(SIGUSR2, receive_ack);
		send_signal(client_id, '\0');
	}
	else
		return (ft_printf("Wrong number of arguments!\n"), 1);
	return (0);
}
