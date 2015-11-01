/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:43:41 by barbare           #+#    #+#             */
/*   Updated: 2015/10/22 18:14:41 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>


/*
** ****************************************************************************
** ft_stream_new
** INPUT:	File descriptor input read(integer)
**			File descriptor output write(integer)
** 			Struct stream like C++ string
** OUTPUT:	Nothing 
** Describe: Create new stream to save a long stream
** ****************************************************************************
*/

void		ft_stream_new(int fdin, int fdout, int fderr, t_stream *stream)
{
	stream->fdin = fdin;
	stream->fdout = fdout;
	stream->fderr = fderr;
	stream->size = 0;
	stream->cursor = 0;
}

/*
** ****************************************************************************
** ft_stream_fill
** INPUT:	Struct stream
** OUTPUT:	Nothing 
** Describe: Read again after stream's create for complete element
** ****************************************************************************
*/

int		ft_stream_fill(t_stream *stream)
{
	if (stream->size > 0 && stream->cursor > 0)
		ft_stream_cr(stream);
	stream->size += read(stream->fdin, &stream->buf[stream->size],
							BUFFSTREAM - stream->size);
	return (stream->size);
} 

/*
** ****************************************************************************
** ft_stream_cr
** INPUT:	Struct stream
** OUTPUT:	Nothing 
** Describe: Carriage return old string to start 
** ****************************************************************************
*/

void		ft_stream_cr(t_stream *stream)
{
	int		i;
	int		lenght;

	i = 0;
	lenght = stream->size - stream->cursor;
	if (stream->cursor < stream->size)
		while (i < lenght)
		{
			stream->buf[i] = stream->buf[stream->size - (stream->cursor + i)];
			i++;
		}
	stream->size -= stream->cursor;
	stream->cursor = 0;
}
