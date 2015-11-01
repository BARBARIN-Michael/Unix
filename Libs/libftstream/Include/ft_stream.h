/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:34:13 by barbare           #+#    #+#             */
/*   Updated: 2015/10/22 18:22:50 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_STREAM_H
# define FT_STREAM_H

# include <stddef.h>
# include <unistd.h>

# define BUFFSTREAM 4096

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
typedef struct		s_stream
{
	char			fdin;
	char			fdout;
	char			fderr;
	int			size;
	int			cursor;
	unsigned int		allread;
	char			buf[BUFFSTREAM];
}					t_stream;

/*
** ****************************************************************************
** ft_stream_new.c
** Describe: create, get and read new data
** ****************************************************************************
*/
void		ft_stream_new(int fdin, int fdout, int fderr, t_stream *stream);
void		ft_stream_cr(t_stream *stream);
int		ft_stream_fill(t_stream *stream);

/*
** ****************************************************************************
** ft_stream_read
** Describe: read in file descriptor the stream
** ****************************************************************************
*/
unsigned int	ft_stream_read(t_stream *stream);
unsigned int	ft_stream_readn(t_stream *stream, int n);
unsigned int	ft_stream_readc(t_stream *stream, unsigned int c);
void		ft_stream_read_full(t_stream *stream);

#endif
