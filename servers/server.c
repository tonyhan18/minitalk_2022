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

# include "../includes/minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *unuse)
{
}

int	main(void)
{
	struct sigaction event;
	
	event.sg_flags = SA_SIGINFO;
	event.sg_sigaction = handler;
	sigaction(USRSIG1, &event, NULL);
	sigaction(USRSIG2, &event, NULL);
	ft_putstr_fd("Server PID : [",1);
	ft_putnbr_fd(getpid(),1);
	ft_putstr_fd("]\n",1);
	while (1)
		pause();
	return (0);
}

