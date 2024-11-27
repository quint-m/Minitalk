/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:42:06 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/30 15:17:11 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	n_length(unsigned long n, int base)
{
	size_t	l;

	l = 0;
	while (n > 0)
	{
		n /= base;
		l++;
	}
	return (l);
}

int	handle_hex(unsigned long n, const char *char_set, char *buffer)
{
	size_t	i;
	size_t	l;
	char	c;

	c = '0';
	l = 0;
	i = n_length(n, 16);
	if (n == 0)
		return (write(1, &c, 1));
	if (i == 0)
		return (-1);
	buffer[i] = '\0';
	while (n > 0)
	{
		buffer[--i] = char_set[(n & 0xF)];
		l++;
		n >>= 4;
	}
	return (write(1, &(buffer[i]), l));
}

int	handle_int(int n, char *buffer)
{
	size_t	i;
	size_t	l;
	int		sign;

	l = 0;
	sign = (n > 0) - (n < 0);
	if (n <= INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		return (write(1, "0", 1));
	if (sign < 0)
		write(1, "-", 1);
	n *= sign;
	i = n_length(n, 10);
	if (i == 0)
		return (-1);
	buffer[i] = '\0';
	while (n > 0)
	{
		buffer[--i] = ((n % 10) + '0');
		l++;
		n /= 10;
	}
	return ((sign < 0) + write(1, &(buffer[i]), l));
}

int	handle_int_u(unsigned int n, char *buffer)
{
	char	c;
	size_t	i;
	size_t	l;

	c = '0';
	l = 0;
	i = n_length(n, 10);
	if (n == 0)
		return (write(1, &c, 1));
	if (i == 0)
		return (-1);
	buffer[i] = '\0';
	while (n > 0)
	{
		buffer[--i] = ((n % 10) + '0');
		l++;
		n /= 10;
	}
	return (write(1, &(buffer[i]), l));
}
