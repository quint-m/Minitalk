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
#include "../libft/libft.h"

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
	// SIGUSR1 = 10, SIGUSR2 = 12
	// SIGUSR1 = 0 (byte)
	// SIGUSR2 = 1 (byte)
	// Sending A (65) = 1000001
	//
	//
	//
	//
	while ((sig = get_next_line(0)))
	{
		kill(PID, ft_atoi(sig));
	}
	/*
	kill(PID, SIGUSR2);
	usleep(1);
	kill(PID, SIGUSR1);
	usleep(1);
	kill(PID, SIGUSR1);
	usleep(1);
	kill(PID, SIGUSR1);
	usleep(1);
	kill(PID, SIGUSR1);
	usleep(1);
	kill(PID, SIGUSR1);
	usleep(1);
	kill(PID, SIGUSR2);
	*/
	return (0);
}
