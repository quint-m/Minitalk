/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:32:12 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 11:40:13 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	in_set(char const c, char const *haystack)
{
	while (*haystack)
	{
		if (*haystack == c)
			return (1);
		haystack++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (end == 0)
		return (ft_strdup(""));
	while (in_set(s1[start], set))
		start++;
	while (in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - (start - 1)));
}
