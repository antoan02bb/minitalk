/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:06:21 by aantonie          #+#    #+#             */
/*   Updated: 2023/12/04 15:08:06 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// READY

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main(void)
// {
//     t_list  Antoan;
//     t_list  jOHN;

//     jOHN.content = (void *)77;
//     jOHN.next = &Antoan;

//     Antoan.content = (void *)45;

//     printf("%d %p",(int)Antoan.content, jOHN.next);

//     return (0);
// }