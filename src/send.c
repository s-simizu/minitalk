/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:22:45 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/09 00:18:28 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits.h>
#include <exit.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>

static void	send_signal(pid_t pid, int signal)
{
	usleep(50);
	if (kill(pid, signal) == -1)
		exit_error("kill failed", "");
	pause();
}

static void	send_byte(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < CHAR_BIT)
	{
		if (is_bit_on(c, i))
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		i++;
	}
}

void	send_msg(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		i++;
	}
}
