/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:10:02 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/03 13:22:07 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check whether s1 or s2 is a null pointer (i.e., s1 == NULL or s2 == NULL)

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	while (*s1)
	{
		s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3[i] = '\0';
	return (s3);
}

// int main()
// {
// 	char s1[] = " ";
// 	char s2[] = "Toni";

// 	char *s3 = ft_strjoin(s1, s2);

// 	if (s3) {
// 		printf("String 1 is: %s\n", s1);
// 		printf("String 2 is: %s\n", s2);
// 		printf("String 3 is: %s\n", s3);
// 		free(s3);
// 	} else {
// 		printf("String 3 is NULL (allocation failed).\n");
// 	}

// 	return 0;
// } 