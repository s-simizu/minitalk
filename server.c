/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/28 00:00:35 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_error.h"
#include <libft.h>
#include <signal.h>

typedef struct sigaction	t_sigaction;

void	handler(int sig)
{
}

int	main(void)
{
	t_sigaction	act1;
	t_sigaction	act2;

	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &act1, NULL) == -1)
		exit_error("sigaction failed", "");
	if (sigaction(SIGUSR2, &act2, NULL) == -1)
		exit_error("sigaction failed", "");
	while (1)
	{
	}
}
