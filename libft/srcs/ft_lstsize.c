/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:57:10 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 18:00:02 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*l;
	int		count;

	if (!lst)
		return (0);
	count = 0;
	l = lst;
	while (l)
	{
		l = l->next;
		count++;
	}
	return (count);
}
