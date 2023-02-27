/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:12:04 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 19:16:14 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_search_index(int val, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == val)
			return (i);
		i++;
	}
	return (-1);
}
