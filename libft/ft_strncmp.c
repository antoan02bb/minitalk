/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:44:33 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/05 20:05:30 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while ((ps1[i] || ps2[i]) && i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	str1[] = "test\200";
// 	const char	str2[] = "test\0";
// 	size_t		chars_to_compare;
// 	int			result; //128 - good
// 	int			result1;

// 	chars_to_compare = 6;
// 	result = strncmp(str1, str2, chars_to_compare);
// 	if (result == 0)
// 		printf("Both strings are identical: %d\n", result);
// 	else if (result > 0)
// 		printf("str1 is bigger than str2: %d\n", result);
// 	else
// 		printf("str2 is bigger than str1: %d\n", result);

// 	result1 = ft_strncmp(str1, str2, chars_to_compare);
// 	if (result1 == 0)
// 		printf("Both strings are identical: %d", result1);
// 	else if (result1 > 0)
// 		printf("str1 is bigger than str2: %d", result1);
// 	else
// 		printf("str2 is bigger than str1: %d", result1);
// 	return (0);
// }
