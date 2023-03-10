/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:22:45 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/14 06:58:01 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_error.h"
#include <limits.h>
#include <signal.h>
#include <unistd.h>

static void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
		exit_error("kill failed", "");
	usleep(100);
}

static void	send_byte(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < CHAR_BIT)
	{
		if (c & 1 << i)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		i++;
	}
}

void	send_msg(pid_t pid, char *msg)
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
	send_byte(pid, bytes[i]);
}
