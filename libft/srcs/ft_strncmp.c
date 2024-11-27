/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:07:57 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 14:10:51 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
/*
int	main(void)
{
	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
}
*/
