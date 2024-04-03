/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:42:01 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/06 13:39:42 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Count the number of occurrences of a delimiter in the 
// input string.
static	size_t	ft_delimeter_count(char const *str, char delimiter)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			counter++;
			while (str[i] && str[i] != delimiter)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (counter);
}

// Calculate the length of a substring within the input string,
// starting from a given position and ending at the next delimiter character.
static	size_t	substring_length(char const *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
	{
		i++;
	}
	return (i);
}

// Free the memory allocated for individual substrings, 
// and the entire array after all iterations.
static	void	free_substrigs(size_t i, char **str_array)
{
	while (i > 0)
	{
		i--;
		free(str_array[i]);
	}
	free(str_array);
}

// Helper function for splitting the input string into 
// substrings based on the specified delimiter.
static	char	
	**split_string(char const *str, char del, char **str_array, size_t dc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dc)
	{
		while (str[j] && str[j] == del)
		{
			j++;
		}
		str_array[i] = ft_substr(str, j, substring_length(&str[j], del));
		if (!str_array[i])
		{
			free_substrigs(i, str_array);
			return (NULL);
		}
		while (str[j] && str[j] != del)
		{
			j++;
		}
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}

// Split the input string into an array of substrings using
// the specified delimiter character.
char	**ft_split(char const *str, char delimiter)
{
	char	**str_array;
	size_t	delimeter_count;

	if (!str)
	{
		return (NULL);
	}
	delimeter_count = ft_delimeter_count(str, delimiter);
	str_array = (char **)malloc(sizeof(char *) * (delimeter_count + 1));
	if (!str_array)
	{
		return (NULL);
	}
	str_array = split_string(str, delimiter, str_array, delimeter_count);
	return (str_array);
}
