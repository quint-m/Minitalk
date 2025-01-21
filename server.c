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
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft/include/libft.h"

static void	empty_state(char *c_code, int *b_count)
{
	*c_code = '\0';
	*b_count = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static char		c;
	static int		count;
	static pid_t	c_id;

	(void) ucontext;
	if (c_id != info->si_pid)
	{
		empty_state(&c, &count);
		c_id = info->si_pid;
	}
	count++;
	if (sig == SIGUSR2)
		c |= 1 << (8 - count);
	if (count == 8)
	{
		if (c)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		c = '\0';
		count = 0;
	}
	kill(c_id, SIGUSR1);
	return ;
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
