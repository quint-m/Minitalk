/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:41:09 by qmennen           #+#    #+#             */
/*   Updated: 2024/10/30 15:17:26 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_char(va_list args, const char *fmt, char *buf)
{
	char	c;

	(void) fmt;
	(void) buf;
	c = (char) va_arg(args, int);
	return (write(1, &c, sizeof(c)));
}

int	print_str(va_list args, const char *fmt, char *buf)
{
	char	*str;

	(void) fmt;
	(void) buf;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

int	print_hex_l(va_list args, const char *fmt, char *buf)
{
	long	n;

	(void) fmt;
	n = va_arg(args, long);
	return (handle_hex((unsigned int)n, "0123456789abcdef", buf));
}

int	print_hex_u(va_list args, const char *fmt, char *buf)
{
	long	n;

	(void) fmt;
	n = va_arg(args, long);
	return (handle_hex((unsigned int)n, "0123456789ABCDEF", buf));
}
