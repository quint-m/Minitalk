/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:27:35 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 14:45:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	i = 0;
	str = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == cc)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
