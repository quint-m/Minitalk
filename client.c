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
	// program PID MSG
	if (argc < 3)
		return (1);

	PID = ft_atoi(argv[1]);

	kill(PID, SIGUSR1);
	kill(PID, SIGUSR1);
	return (0);
}
