/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:18:14 by aantonie          #+#    #+#             */
/*   Updated: 2023/12/11 04:25:29 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// void	printCarBrand(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	// Create linked list nodes
// 	t_list *toyota = malloc(sizeof(t_list));
// 	toyota->content = "Toyota";
// 	toyota->next = NULL;

// 	t_list *tesla = malloc(sizeof(t_list));
// 	tesla->content = "Tesla";
// 	tesla->next = NULL;

// 	// Connect nodes to form a linked list
// 	toyota->next = tesla;

// 	ft_lstiter(toyota, printCarBrand);

// 	free(toyota);
// 	free(tesla);

// 	return (0);
// }