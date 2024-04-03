/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:02:43 by aantonie          #+#    #+#             */
/*   Updated: 2023/10/18 12:16:28 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memset() function writes len bytes of value c
// (converted to an unsigned char) to the string b
// int t, because n is size_t and i cant comprare it with i

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*temp;
	int		t;

	i = 0;
	temp = (char *)s;
	t = n;
	while (i < t)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
