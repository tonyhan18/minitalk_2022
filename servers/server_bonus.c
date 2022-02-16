/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:18:46 by chahan            #+#    #+#             */
/*   Updated: 2022/02/15 16:18:47 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *unuse)
{
	static unsigned char c = 0x00;
	static int client_pid = 0;
	static int index = 0;

	(void)unuse;
	if(!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++index == 8)
	{
		index = 0;
		if (c == 0x00)
		{
			ft_putchar_fd('\n', 1);
			client_pid = 0;
			return;
		}
		ft_putchar_fd(c, 1);
		c=0x00;
		kill(client_pid, SIGUSR1);
	}else {
		c = c << 1;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction event;
	
	event.sa_flags = SA_SIGINFO;
	event.sa_sigaction = handler;
	sigaction(SIGUSR1, &event, NULL);
	sigaction(SIGUSR2, &event, NULL);
	ft_putstr_fd("Server PID : [",1);
	ft_putnbr_fd(getpid(),1);
	ft_putstr_fd("]\n",1);
	while (1)
		pause();
	return (0);
}

