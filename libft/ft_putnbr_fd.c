/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 02:05:42 by aantonie          #+#    #+#             */
/*   Updated: 2024/05/15 17:38:56 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 11 is the length of "-2147483648"
int	ft_putnbr_fd(long n, int fd)
{
	unsigned int	num;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	num = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + '0'), fd);
	return (1);
}

// 1. Handling edge case
// 2. Handle negative numbers (make n a positive number)
// 3. n % 10 -> взимам единицата на числото
