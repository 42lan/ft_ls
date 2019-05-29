/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 04:48:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 15:02:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** buffer_full() checks if buffer is full and return 1, otherwise it return 0.
*/

int		buffer_full(t_buffer *buffer)
{
	return (buffer->index == BUFF_SIZE);
}

/*
** print_buffer() prints to stdout the content of buffer as much as value
** of index is setted and resets the index to 0 so that buffer fills again
*/

void	print_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->index);
	buffer->index = 0;
}

/*
** write_char() checks fullness of buffer in order to be sure that a new
** character can be store and increase value of length.
*/

void	write_char(t_buffer *buffer, char c)
{
	if (buffer_full(buffer) == 1)
		print_buffer(buffer);
	buffer->content[buffer->index++] = c;
	buffer->length++;
}

/*
** write_str() fills the buffer with the specified length of characters from
** received string.
*/

void	write_str(t_buffer *buffer, char *str, int length)
{
	if (str)
		while (*str && length--)
			write_char(buffer, *str++);
}
