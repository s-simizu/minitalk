/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:40:10 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 00:28:20 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(int *array, size_t size)
{
	bool	swapped;
	size_t	i;

	if (!array || !size)
		return ;
	swapped = true;
	i = 0;
	while (swapped)
	{
		swapped = false;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				ft_swap(&array[i], &array[i + 1]);
				swapped = true;
			}
			i++;
		}
		i = 0;
		size--;
	}
}
