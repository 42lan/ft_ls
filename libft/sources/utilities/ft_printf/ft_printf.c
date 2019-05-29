/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/26 17:10:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf() iterate each character of given format string until it reach '%'
** which define a placeholder. When '%' is reached, parsing() takes over to
** determine type of placeholder and call the appropriate function to this type.
** On each iteration, fullness of buffer is checked:
**		In case of fullnes, buffer is printed and its index is setted to 0
**		to overwrite the content of buffer until it fills up.
**		Otherwise, a new character is stored in buffer.
** When while() loop ends, buffer is checked again to be printed.
*/

int				ft_printf(const char *format, ...)
{
	t_info		info;

	if (!format)
		return (-1);
	va_start(info.ap, format);
	initialize_buffer(&info.buffer);
	while (*format)
	{
		if (buffer_full(&info.buffer) == 1)
			print_buffer(&info.buffer);
		if (*format == '%')
		{
			format++;
			parsing(&format, &info);
			if (*format == 0)
				break ;
		}
		else
			write_char(&info.buffer, *format);
		++format;
	}
	if (info.buffer.index != 0)
		print_buffer(&info.buffer);
	va_end(info.ap);
	return (info.buffer.length);
}
