/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:04:51 by qmennen           #+#    #+#             */
/*   Updated: 2024/11/27 21:05:47 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/siginfo_t.h>
#include <signal.h>
#include "libft/include/libft.h"

static int	g_acknowledged = 0;

void	send_byte(int PID, const char c)
{
	int				i;
	int				kreturn;
	unsigned char	cc;

	cc = (unsigned char) c;
	i = 7;
	while (i >= 0)
	{
		g_acknowledged = 0;
		if (((cc >> i) & 1) == 1)
			kreturn = kill(PID, SIGUSR2);
		else
			kreturn = kill(PID, SIGUSR1);
		if (kreturn < 0)
			exit(1);
		while (g_acknowledged == 0)
			pause();
		i--;
	}
}

void	send_message(int PID, const char *msg)
{
	if (!msg)
		return ;
	while (*msg)
	{
		send_byte(PID, *msg);
		msg++;
	}
}

static void	handle_response(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signal;
	if (g_acknowledged == 0)
		g_acknowledged = 1;
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*sig;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_response;
	sigemptyset(&sa.sa_mask);
	if (argc < 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	sig = ft_strjoin(argv[2], "\0");
	send_message(pid, sig);
	send_message(pid, "\n");
	free(sig);
	return (0);
}
