/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:42:55 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/08 19:44:31 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	int				idx;

	idx = 0;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	while (n > 0)
	{
		cdest[idx++] = *csrc;
		csrc++;
		n--;
	}
	return (dest);
}
