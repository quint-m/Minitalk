/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:52:02 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/30 14:52:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_int(va_list args, const char *fmt, char *buf)
{
	int	n;

	(void)fmt;
	n = va_arg(args, int);
	return (handle_int(n, buf));
}

int	print_int_unsigned(va_list args, const char *fmt, char *buf)
{
	unsigned int	n;

	(void)fmt;
	n = va_arg(args, unsigned int);
	return (handle_int_u(n, buf));
}

int	print_pointer(va_list args, const char *fmt, char *buf)
{
	void	*ptr;

	(void)fmt;
	ptr = (void *) va_arg(args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2)
		+ handle_hex((unsigned long) ptr, "0123456789abcdef", buf));
}

int	print_percent(va_list args, const char *fmt, char *buf)
{
	(void)fmt;
	(void)buf;
	(void)args;
	return (write(1, "%", 1));
}
