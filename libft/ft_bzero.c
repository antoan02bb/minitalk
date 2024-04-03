/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:17:23 by aantonie          #+#    #+#             */
/*   Updated: 2023/10/18 12:26:03 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1. memset - part of Standard C Library
// 2. bzero - legacy function in older versions of the C library
// memset - preferred and standard way to zero out memory is memset

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
