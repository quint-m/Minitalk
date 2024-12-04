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

#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	send_byte(int PID, const char c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char) c;
	i = 7;
	while (i >= 0)
	{
		if (((cc >> i) & 1) == 1)
			kill(PID, SIGUSR2);
		else 
			kill(PID, SIGUSR1);
		i--;
		usleep(300);
	}
}

void	send_message(int PID, const char *msg)
{
	if (!msg)
		return;
	while (*msg)
	{
		send_byte(PID, *msg);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	PID;
	char*	sig;
	if (argc < 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		return (1);
	}
	PID = ft_atoi(argv[1]);
	sig = ft_strjoin(argv[2], "\0");
	send_message(PID, sig);
	send_message(PID, "\n");
	free(sig);
	return (0);
}
