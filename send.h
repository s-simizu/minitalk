/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:24:58 by sshimizu          #+#    #+#             */
/*   Updated: 2023/03/01 19:34:51 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_H
# define SEND_H

# include <signal.h>

void	send_msg(pid_t pid, char *msg);

#endif
