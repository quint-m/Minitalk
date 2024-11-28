/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:42:54 by qmennen           #+#    #+#             */
/*   Updated: 2024/11/19 17:15:19 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include "stdlib.h"

char	*get_next_line(int fd);

char	*ft_strchr(const char *s1, const char c);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *s1);

char	*ft_join(char *buffer, char *buf);

#endif
