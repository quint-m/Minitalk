/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:36:54 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 12:43:32 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len > size)
		dest_len = size;
	if (dest_len == size)
		return (dest_len + src_len);
	if (src_len <= size - dest_len - 1)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
