/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:24:32 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 11:25:21 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;

	idx = 0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (*s1)
	{
		result[idx++] = *s1;
		s1++;
	}
	while (*s2)
	{
		result[idx++] = *s2;
		s2++;
	}
	result[idx] = '\0';
	return (result);
}
