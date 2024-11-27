/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:16 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 14:48:14 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && (*(unsigned char *)s1 == *(unsigned char *)s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
/*
int	main(void)
{
	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 0));
	printf("%d\n", memcmp("abcdefghij", "abcdefgxyz", 0));
}
*/
