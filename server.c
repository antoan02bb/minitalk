/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:47 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/14 15:33:14 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @param bit_index - keep track of the position of the bit in current_char
 * 
 * @brief 1. shift the bits of current_char one position to the left, so the rigthmost(LSB) becomes 0 and makes space for the next bit
 * @brief 2. append the received signal(0 or 1) to current_char
 * @brief 3. reset the bit_index to 0 and the current_char to 0
*/
static void	signal_handler(int signal)
{
	static char	current_char;
	static int	bit_index;

	current_char <<= 1;
	
	if (signal == SIGUSR1)
		current_char |= 1;
	
	bit_index++;

    // if all 8 bits have been received
	if (bit_index == 8)
	{
		ft_printf("%c", current_char);
		
		current_char = 0;
		bit_index = 0;
	}
        
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of arguments"), 1);
	// enter an infinite loop and wait for signals
	ft_printf("The ID of the server is: %d", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
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