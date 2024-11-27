/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:47 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/16 18:45:10 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *l_new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = l_new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = l_new;
	}
}
