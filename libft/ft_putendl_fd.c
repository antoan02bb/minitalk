/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:19:00 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/06 00:29:09 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
// 	char *str = "Hello World";
// 	int fileDescriptor = 1;

// 	ft_putendl_fd(str, fileDescriptor);
// 	printf("I am testing for emty line");

// 	return 0;
// }

// 1.Ако write фуцкцията е write(fd, s, 1) то принтира 
// само един символ от инпут стринга 

// 2. Принтирането продължаваше неограничено, заради  
// while луупа, който водеше до infinite loop