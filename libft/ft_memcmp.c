/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:34:35 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/04 13:49:04 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main() {

// 	const char str[] = "Antoan";
// 	const char str1[] = "Antop";
// 	unsigned int len = 6;

// 	int result = ft_memcmp(str, str1, len);

// 	if (result == 0)
// 		printf("The 2 strings are identical: %d", result);
// 	else
// 		printf("The strings are not identical!\n");
// 		printf("The difference is: %d", result);

// 	return 0;
// }
