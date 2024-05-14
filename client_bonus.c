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
 * @brief convert the character(from the message in the command line arguments) into 8 bits and sends each bit as a signal to the server
 * @param pid the proces ID pf the
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
		if (character % 2 == 0)
		{
			kill(pid, SIGUSR2); // SIGUSR2 to represent a 0 bit
		}
		else
		{
			kill(pid, SIGUSR1); // SIGUSR1 to represent a 1 bit
		}
		// client waits 42 microseconds - te elay alows the server to process the received signal
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

        signal(SIGUSR2, receive_ack);
	    send_signal(client_id, '\0');
	}
	else
		return(ft_printf("ERROR"), 1);
	return (0);
}