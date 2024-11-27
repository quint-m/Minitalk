/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_striteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:13:38 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 16:15:46 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int i, char *))
{
	size_t	l;
	size_t	i;

	l = ft_strlen(s);
	i = 0;
	while (i < l)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
