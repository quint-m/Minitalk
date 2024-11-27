/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:34:17 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 16:36:05 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (*s)
	{
		res[i++] = *s++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	*dest;

	dest = ft_strdup("hello world");
	printf("%s\n", dest);
}
*/
