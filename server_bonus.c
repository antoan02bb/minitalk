#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @param c current character
*/
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int		bit_index; // keep track of the position of the bit in c

	(void)context;
	// 1. extract the bit value of the received signal(0 or 1) and append it it to c
	if (signal == SIGUSR1)
		c |= (signal == SIGUSR1);
	bit_index++;

    // if all 8 bits have been received
	if (bit_index == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
        ft_printf("%c", c);
	}
    else
		/* shift the bits of c one position to the left
		by doing so, the rigthmost(LSB) becomes 0 and makes space for the next bit */
        c <<= 1;
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
		return (ft_printf("ERROR"), 1);
	// enter an infinite loop and wait for signals
	ft_printf("The ID of the server is: %d", getpid());
	while (1)
		pause();
	return (0);
}