/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/09 00:20:01 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>
#include <errno.h>
#include <exit.h>
#include <info.h>
#include <libft.h>
#include <signal.h>

volatile t_info	g_received_info;

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	g_received_info.sig = sig;
	g_received_info.pid = info->si_pid;
}

static void	bits_to_char(sig_atomic_t sig)
{
	static char	c;
	static int	bit;

	if (sig == SIGUSR1)
		bit_on(&c, bit);
	if (bit == 7)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
		return ;
	}
	bit++;
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
		pause();
		bits_to_char(g_received_info.sig);
		usleep(50);
		if (kill(g_received_info.pid, SIGUSR1) == -1)
			exit_error("kill failed", "");
		g_received_info.pid = 0;
	}
}
