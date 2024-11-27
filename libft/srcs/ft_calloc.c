/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:13 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/10 15:45:47 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size && nmemb > (size_t)-1 / size)
		return (0);
	nmemb *= size;
	res = malloc(nmemb);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb);
	return (res);
}
