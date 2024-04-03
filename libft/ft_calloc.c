/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:39:52 by aantonie          #+#    #+#             */
/*   Updated: 2023/10/26 12:12:28 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates a block of memory for an array of elements
// initializes that memory to zero

// returns - a pointer to the allocated memory
// arguments - num_elements, - size_element
// a block of memory = count of elements * size of one element

// void* in memory allocation - The void* pointer is a generic pointer
// type that can be used to point to memory of any data type.
// stores the address of the allocated's memory bloc

// Initialize the allocated memory to zero
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= 2147483647 || size >= 2147483647)
		return (NULL);
	ptr = (void *) malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// #include <stdio.h>

// int main() {
//     size_t count = 5;
//     size_t size = sizeof(int);

//     int *allocatedArray = (int *)ft_calloc(count, size);

//     if (allocatedArray) {
//         printf("Memory allocation successful:\n");

//         size_t i = 0;
//         while (i < count) {
//             printf("allocatedArray[%zu] = %d\n", i, allocatedArray[i]);
//             i++;
//         }

//         free(allocatedArray);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }