/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:56:11 by qmennen           #+#    #+#             */
/*   Updated: 2024/11/27 21:06:17 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft/include/libft.h"

static void	empty_state(int *c_code, int *b_count)
{
	*c_code = 0;
	*b_count = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int	c;
	static int	count;
	static int	c_id;
	int			w_res;

	(void) ucontext;
	w_res = 0;
	if (c_id != info->si_pid)
	{
		empty_state(&c, &count);
		c_id = info->si_pid;
	}
	if (sig == SIGUSR1)
		c <<= 1;
	else
		c = (c << 1) | 1;
	if ((++count) == 8)
	{
		w_res = write(1, (char *)(&c), 1);
		empty_state(&c, &count);
	}
	if (w_res < 0)
		exit(1);
	kill(c_id, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	ft_printf("Minitalk Server Running On PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
