/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:47 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/15 18:15:55 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief 	1. Shift the bits of current_char one position to the left,
 * 				so the rigthmost(LSB) becomes 0 and makes space for the next bit
 * @brief 	2. Append the received signal(0 or 1) to current_char
 * @brief 	3. Reset the bit_index to 0 and the current_char to 0
 *
 * @param 	bit_index - keep track of the position of the bit in current_char
 */
static void	signal_handler(int signal)
{
	static char	current_char;
	static int	bit_index;

	current_char <<= 1;
	if (signal == SIGUSR1)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", current_char);
		current_char = 0;
		bit_index = 0;
	}
}

/**
 * @note in the end enter an infinite loop and wait for signals
 */
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return (ft_printf("Wrong number of arguments"), 1);
	ft_printf("The ID of the server is: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
