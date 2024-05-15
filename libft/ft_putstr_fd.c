/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:28:41 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/15 02:19:14 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

// #include <unistd.h>

// int main()
// {
// 	char *str = "Hello World";
// 	int fileDescriptor = 1;

// 	ft_putstr_fd(str, fileDescriptor);

// 	return 0;
// }