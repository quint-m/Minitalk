/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:25:26 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/30 14:18:28 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_fmt	*get_formats(void)
{
	t_fmt	*fmt_types;

	fmt_types = ft_calloc(TOKEN_COUNT + 1, sizeof(t_fmt));
	if (!fmt_types)
		return (NULL);
	fmt_types[0] = (t_fmt){'c', print_char};
	fmt_types[1] = (t_fmt){'s', print_str};
	fmt_types[2] = (t_fmt){'x', print_hex_l};
	fmt_types[3] = (t_fmt){'X', print_hex_u};
	fmt_types[4] = (t_fmt){'p', print_pointer};
	fmt_types[5] = (t_fmt){'i', print_int};
	fmt_types[6] = (t_fmt){'d', print_int};
	fmt_types[7] = (t_fmt){'u', print_int_unsigned};
	fmt_types[8] = (t_fmt){'%', print_percent};
	fmt_types[9] = (t_fmt){'\0', NULL};
	return (fmt_types);
}

int	print_token(const char *format, char *buffer, va_list args, int *fmt_i)
{
	t_fmt		*fmt_types;
	int			i;

	fmt_types = get_formats();
	i = 0;
	if (!fmt_types)
		return (-1);
	while (fmt_types[i].token)
	{
		if (!format[*fmt_i] || format[*fmt_i] != fmt_types[i].token)
		{
			i++;
			continue ;
		}
		i = fmt_types[i].fn(args, format, buffer);
		free(fmt_types);
		return (i);
	}
	free(fmt_types);
	return (write(1, "%", 1));
}
