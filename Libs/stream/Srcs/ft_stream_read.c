/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:40:45 by barbare           #+#    #+#             */
/*   Updated: 2015/10/22 18:43:23 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>
#include <libft.h>

unsigned int		ft_stream_read(t_stream *stream)
{
	int		cursor_read;

	cursor_read = write(stream->fdout,  &stream->buf[stream->cursor],
						stream->size - stream->cursor);
	stream->cursor = 0;
	stream->size = 0;
	return (cursor_read);
}

unsigned int		ft_stream_read_n(t_stream *stream, unsigned int n)
{
	int		cursor_read;

	if (n >= (stream->size - stream->cursor))
		return (ft_stream_read(stream));
	else
	{
		cursor_read = write(stream->fdout, &stream->buf[stream->cursor], n);
		stream->cursor += n;
	}
	return (cursor_read);
		
}	


unsigned int		ft_stream_read_c(t_stream *stream, int c)
{
	int			cursor_read;
	char		*ptr;

	if ((ptr = ft_strchr(stream->buf, c)) == NULL)
		return (ft_stream_read(stream));
	else
	{
		cursor_read = write(stream->fdout, &stream->buf[stream->cursor],
								ptr - stream->buf);
		stream->cursor += n;
	}
	return (cursor_read);
		
}	

unsigned int		ft_stream_read_expr(t_stream *stream, char *str)
{
	int		cursor_read;
	char	*ptr;

	if ((ptr = ft_strstr(stream->buf, str)) == NULL)
		return (ft_stream_read(stream));
	else
	{
		cursor_read = write(stream->fdout, &stream->buf[stream->cursor],
								ptr - stream->buf);
		stream->cursor += n;
	}
	return (cursor_read);
		
}	
