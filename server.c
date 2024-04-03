/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:47 by aantonie          #+#    #+#             */
/*   Updated: 2024/04/03 18:34:46 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	signal_handler(int signal)
{
	char	current_char = 0;
	int		bit_index = 0; // keep track of the position of the bit in current_char

	// 1. extract the bit value of the received signal(0 or 1) and append it it to current_char
	current_char |= (signal == SIGUSR1);
	bit_index++;

    // if all 8 bits have been received
	if (bit_index == 8)
	{
        ft_printf("%c", current_char);
	}
    else
		/* shift the bits of current_char one position to the left
		by doing so, the rigthmost(LSB) becomes 0 and makes space for the next bit */
        current_char <<= 1;
}

int	main(void)
{
	ft_printf("The ID of the server is: %d", getpid());
	signal(SIGUSR2, signal_handler);
	signal(SIGUSR1, signal_handler);
	// enter an infinite loop and wait for signals
	while (1)
		pause();
	return (0);
}
/*
	* @param siginfo_t In signal handling,
		it allows programs to handle signals in a more sophisticated
		manner,
			enabling them to gather detailed information about the cause and context of the signal.

	static void signal_handler(int signal, siginfo_t *info, void *context)

	* @brief sa_handler and sa_sigaction are almost equivalent,
		the latter is complex

	retunrs 0 - if it successfuly registers the signal handler,
	specified by the sigaction struct

	struct sigaction sa;
	sa.sa_sigaction = signal_handler;

	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
*/

//  When i pass a function as another function's argument,
//	I am actually passing a pointer to that function and not the function itself