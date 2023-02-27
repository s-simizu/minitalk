/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:59:29 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/28 00:50:13 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_error.h"
#include <libft.h>
#include <signal.h>

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

static void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
		exit_error("kill failed", "");
}

static void	send_byte(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < CHAR_BIT)
	{
		if (c & 0x01)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		c >>= 1;
	}
}

static void	send_msg(pid_t pid, char *msg)
{
	unsigned char	*bytes;
	int				i;

	bytes = (unsigned char *)msg;
	i = 0;
	while (bytes[i])
	{
		send_byte(pid, bytes[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		exit_error("usage: client [PID] [MSG]", "");
	send_msg(get_server_pid(argv[1]), argv[2]);
}
