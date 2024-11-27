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

#include <bits/types/siginfo_t.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	ft_printf("Received signal %d\n", sig);
	ft_printf("Received code %d\n", info->si_code);
}

int	main(void)
{
	struct	sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("You fucked up\n");
		exit(1);
	}
	ft_printf("Server running and listening on PID: %d...\n", getpid());
	while (1)
	{
		sleep(1);
	}
	return (0);
}
