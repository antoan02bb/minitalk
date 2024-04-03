/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:48 by aantonie          #+#    #+#             */
/*   Updated: 2023/11/02 14:44:59 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1. Apply a given function f to each character in the input string s,
 	passing the index of the character as the first argument and a 
 	pointer to the character as the second argument	*/

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
