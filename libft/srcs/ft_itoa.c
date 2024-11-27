/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:20:49 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/15 14:25:59 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	int_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*assign_memory(size_t size)
{
	char	*mem;

	mem = malloc(size);
	if (!mem)
	{
		return (NULL);
	}
	mem[0] = '0';
	return (mem);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	size_t	idx;
	size_t	len;

	nbr = n;
	len = int_len(nbr);
	result = assign_memory(len + 1);
	if (!result)
		return (NULL);
	idx = len - 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[idx--] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}
