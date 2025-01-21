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
#include <unistd.h>
#include "libft/include/libft.h"

static volatile int	g_acknowledged = 0;

void	send_byte(int PID, unsigned char c)
{
	int				i;
	int				kreturn;

	i = 0;
	while (i < 8)
	{
		g_acknowledged = 0;
		if ((c & 128) == 128)
			kreturn = kill(PID, SIGUSR2);
		else
			kreturn = kill(PID, SIGUSR1);
		if (kreturn < 0)
			exit(1);
		c <<= 1;
		usleep(300);
		while (!g_acknowledged)
			if (pause() == -1)
				usleep(300);
		i++;
	}
}

void	send_message(int PID, char *msg)
{
	if (!msg)
		return ;
	while (*msg)
	{
		send_byte(PID, *msg);
		msg++;
	}
	send_byte(PID, '\0');
}

static void	handle_response(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signal;
	g_acknowledged = 1;
}

static int	retrieve_pid(const char *pid)
{
	size_t	i;
	int		pid_value;

	if (!pid || !pid[0])
		exit(1);
	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("Illegal PID value: %c\n", pid[i]);
			exit(1);
		}
		i++;
	}
	pid_value = ft_atoi(pid);
	if (pid_value < 0)
	{
		ft_printf("PID should be a positive value\n");
		exit(1);
	}
	return (pid_value);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_response;
	sigemptyset(&sa.sa_mask);
	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	pid = retrieve_pid(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
