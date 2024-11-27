/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:22:53 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 12:23:44 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*(src + len))
		len++;
	while (size > 1 && *src)
	{
		*(dst++) = *(src++);
		size--;
	}
	if (size > 0)
	{
		*dst = '\0';
	}
	return (len);
}
