/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:25:02 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/05 23:36:44 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// What is a file descriptor?
// write function in c

// int main()
// {
// 	char character = 'A';
// 	int fileDescriptor = 1;

// 	ft_putchar_fd(character, fileDescriptor);

// 	return 0;
// }