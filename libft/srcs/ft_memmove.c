/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:54:57 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/08 20:02:27 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*csrc;
	unsigned char		*cdest;

	csrc = (const unsigned char *) src;
	cdest = (unsigned char *) dst;
	if (dst == src)
		return (dst);
	if (dst <= src)
	{
		while (len--)
		{
			*cdest++ = *csrc++;
		}
	}
	else if (dst > src)
	{
		cdest += len - 1;
		csrc += len - 1;
		while (len--)
		{
			*cdest-- = *csrc--;
		}
	}
	return (dst);
}
