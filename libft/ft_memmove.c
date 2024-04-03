/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:22:23 by aantonie          #+#    #+#             */
/*   Updated: 2023/10/19 12:14:09 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// What does memmove do? -> copies len bytes from string src to string dst
// 1. sizeof(int) * 10 - the size of 1 int times 10(in general)
// 2. memmove() can handle overlapping destination and source blocks of memory
// 3. otherwise memcpy is better to use

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			t;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	t = len;
	if (dst > src)
	{
		while (t > 0)
		{
			dest[t - 1] = source[t - 1];
			t--;
		}
	}
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	int source[10]= {1,2,3,4,5,6,7,8,9,10};
// 	int destination[10];

// 	memmove(destination, source, sizeof(int) * 10);

// 	int i;

// 	i = 0;
// 	while (i < 10)
// 	{

// 	}

// 	return 0;
// }
