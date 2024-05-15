/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 05:36:12 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/15 18:15:54 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @param bit_index - keep track of the position of the bit in current_char
 *
 * @brief 1. shift the bits of current_char one position to the left,
	so the rigthmost(LSB) becomes 0 and makes space for the next bit
 * @brief 2. append the received signal(0 or 1) to current_char
 * @brief 3. reset the bit_index to 0 and the current_char to 0
 */
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int	bit_index;

	(void)context;
	current_char <<= 1;
	if (signal == SIGUSR1)
		current_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", current_char);
		current_char = 0;
		bit_index = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 1)
		return (ft_printf("Wrong number of arguments"), 1);
	ft_printf("The ID of the server is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

// t😀🤢🙄👻💀👽👾🤖👫👩‍❤️‍👨ئΨΨΨΨΨఔఔఔఔఔ⍇⌚⏩⑳⽷⻤⽋ぉネest characters to print
//