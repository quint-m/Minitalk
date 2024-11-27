/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:50:39 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 14:55:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	offset;

	if (little == big)
		return ((char *)big);
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (len && *big)
	{
		offset = 0;
		while (len > offset && *(big + offset) == *(little + offset)
			&& *(big + offset))
		{
			offset++;
		}
		if (*(little + offset) == '\0')
			return ((char *)(big));
		len--;
		big++;
	}
	return (NULL);
}
