/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:25:56 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/30 15:17:55 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_buffer(char *buffer, size_t *size)
{
	if (*size > 0)
		write(1, &(*buffer), *size);
	*size = 0;
}

static void	initialize(int *a, int *b, int *c, size_t *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

static int	process_format(const char *fmt, char *buf, va_list args, size_t *bi)
{
	int			i;
	int			printed_chars;
	int			token_result;

	initialize(&i, &printed_chars, &token_result, bi);
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			buf[(*bi)++] = fmt[i];
			printed_chars++;
		}
		else
		{
			print_buffer(buf, bi);
			i++;
			token_result = print_token(fmt, buf, args, &(i));
			if (token_result < 0)
				return (-1);
			printed_chars += token_result;
		}
		i++;
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	char		*buffer;
	size_t		printed_chars;
	size_t		buffer_idx;
	va_list		args;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char *));
	if (!buffer || !format)
		return (-1);
	va_start(args, format);
	printed_chars = process_format(format, buffer, args, &buffer_idx);
	va_end(args);
	print_buffer(buffer, &buffer_idx);
	free(buffer);
	return (printed_chars);
}
