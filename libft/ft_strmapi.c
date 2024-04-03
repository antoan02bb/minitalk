/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:38:16 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/02 14:44:56 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s - string | f - funtion pointer
// Returns a new string by applying the function
// f on to each character in the input string

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (str == NULL || f == NULL)
		return (NULL);
	i = 0;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
