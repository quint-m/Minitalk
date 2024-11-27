/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:07:29 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/08 15:10:10 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = (unsigned char) c;
		n--;
		dest++;
	}
	return (s);
}
