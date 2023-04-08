/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:25:53 by sshimizu          #+#    #+#             */
/*   Updated: 2023/04/08 23:32:34 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include <signal.h>

typedef struct s_info
{
	volatile sig_atomic_t	sig;
	volatile sig_atomic_t	pid;
}							t_info;

#endif
