/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:18:40 by chahan            #+#    #+#             */
/*   Updated: 2022/02/15 16:18:41 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"
#include <stdio.h>

void	connection_terminate(pid_t server_pid)
{
}

void	sendToServer(char *s, pid_t pid)
{
	static int i = 8;
	static char* send_str;
	static unsigned char c;
	static pid_t serv_pid;

	// save data
	if (s)
	{
		send_str = s;
		serv_pid = pid;
		c = *s;
	}

	// char is end
	if (i == 0)
	{
		i = 8;
		c = *(++str);
		// no more word
		if(!c)
		{
			while (i--)
			{
				usleep(50);
				kill(serv_pid, SIGUSR2);
			}
			exit(0);
		}
	}

	// send msg
	if (c && (c >> --i) & 0x01 )
		kill(serv_pid, SIGUSR1);
	else if (c)
		kill(serv_pid, SIGUSR2);
}

void	handler(int sig, siginfo_t *siginfo, void *unuse)
{
	static int rcv_bytes = 0;
	(void)siginfo;
	(void)unuse;
	if(sig == SIGUSER1)
	{
		ft_putstr_fd("\tReceive Bit : ", 1);
		ft_putnbr_fd(++rcv_bytes, 1);
	}
	sendToServer(0,0);
}

int	main(int argc, char **argv)
{
	struct sigaction event;
	if(argc != 3 || !(99 < ft_atoi(argv[1]) && ft_atoi(argv[1]) < 99999))
	{
		ft_putstr_fd("\tHow to use : ./client [99 < PID < 99999] [msg]", 1)
		return (1);
	}
	event.sa_flags = SA_SIGINFO;
	event.sa_sigaction = handler;
	sigaction(SIGUSR1, &event, NULL);
	sigaction(SIGUSR2, &event, NULL);
	ft_putstr_fd("Send to Server : ",1);
	ft_putnbr_fd(ft_strlen(argv[2]),1)
	ft_putchar_fd('\n',1);
	sendToServer(argv[2], ft_atoi(argv[1]))
	while (1)
		pause();
	return (0);
}
