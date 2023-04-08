/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:26:27 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/08 23:59:45 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	bit_on(char *c, int n)
{
	*c |= 1 << n;
}

bool	is_bit_on(char c, int n)
{
	int	mask;

	mask = 1 << n;
	if ((c & mask) != 0)
		return (true);
	else
		return (false);
}
