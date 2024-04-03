/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:41:56 by aantonie          #+#    #+#             */
/*   Updated: 2023/12/07 23:55:45 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters:
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be added to the list
Description:
	Adds the node ’new’ at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
