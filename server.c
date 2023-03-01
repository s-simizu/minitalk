/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/01 19:38:49 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_error.h"
#include <errno.h>
#include <libft.h>
#include <signal.h>

static void	handler(int sig, siginfo_t *info, void *context)
{
	static volatile sig_atomic_t	c;
	static volatile sig_atomic_t	bit;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	if (bit != 7)
	{
		bit++;
		return ;
	}
	write(STDOUT_FILENO, (const void *)&c, 1);
	if (c == 0)
	{
		usleep(10);
		kill(info->si_pid, SIGUSR1);
	}
	c = 0;
	bit = 0;
}

static void	set_sigaction(struct sigaction *act)
{
	ft_bzero(act, sizeof(struct sigaction));
	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = handler;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		exit_error("sigaction failed", "");
	if (sigaction(SIGUSR2, act, NULL) == -1)
		exit_error("sigaction failed", "");
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());
	set_sigaction(&act);
	while (1)
	{
		if (errno == EINVAL || errno == EPERM || errno == ESRCH)
			exit_error("kill failed", "");
	}
}
