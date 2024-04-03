/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:56:15 by aantonie          #+#    #+#             */
/*   Updated: 2023/12/06 03:00:51 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Takes as a parameter a node and frees the memory of the node's content
	using the function 'del' given as a parameter and free the node.
	The memory of 'next' must not be freed.
    The content data of the node is of type void *
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
