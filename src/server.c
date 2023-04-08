/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/08 21:07:59 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <exit_error.h>
#include <libft.h>
#include <signal.h>

volatile sig_atomic_t	g_kill_error;

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static volatile sig_atomic_t	c;
	static volatile sig_atomic_t	bit;

	(void)ucontext;
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
		usleep(1000);
		if (kill(info->si_pid, SIGUSR1) == -1)
			g_kill_error = 1;
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
	g_kill_error = 0;
	while (1)
	{
		pause();
		if (g_kill_error)
			exit_error("kill failed", "");
	}
}
