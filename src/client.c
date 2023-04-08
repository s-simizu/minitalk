/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:29 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/08 20:34:51 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit_error.h>
#include <send.h>
#include <libft.h>
#include <signal.h>
#include <unistd.h>

static void	handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "OK\n", 3);
}

static pid_t	get_server_pid(char *s)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			exit_error("illegal pid: ", s);
		i++;
	}
	pid = ft_atoi(s);
	if (pid < 0)
		exit_error("illegal pid: ", s);
	return (pid);
}

static void	set_sigaction(struct sigaction *act)
{
	ft_bzero(act, sizeof(struct sigaction));
	act->sa_handler = handler;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		exit_error("sigaction failed", "");
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	pid_t				pid;

	if (argc != 3)
		exit_error("usage: client [PID] [MSG]", "");
	pid = get_server_pid(argv[1]);
	set_sigaction(&act);
	send_msg(pid, argv[2]);
	pause();
}
