/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:05:35 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 12:08:38 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			words++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (words);
}

static void	*free_memory(char **mem, int j)
{
	while (j >= 0)
		free(mem[j--]);
	free(mem);
	return (NULL);
}

static void	init_memory(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		start;
	int		length;

	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	init_memory(&start, &length, &i);
	while (i < count_words(s, c))
	{
		while (*(s + start) == c && *(s + start) != '\0')
			start++;
		while (*(s + start + length) != c && *(s + start + length) != '\0')
			length++;
		dest[i] = ft_substr(s, start, length);
		if (!dest[i])
			return (free_memory(dest, i));
		start += length;
		length = 0;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
