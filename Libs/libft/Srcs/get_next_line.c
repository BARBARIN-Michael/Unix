/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 06:04:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/30 14:59:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static ssize_t	ft_len_to_endline(int fd, t_buf *buf)
{
	char	*endline;

	if (buf->cursor >= (size_t)buf->size)
	{
		buf->size = read(fd, buf->buf, BUFF_SIZE);
		buf->cursor = 0;
	}
	if (buf->size <= 0)
		return (-1);
	endline = ft_memchr(buf->buf + buf->cursor, '\n', buf->size - buf->cursor);
	if (endline == NULL)
		return (-1);
	else
		return (endline - (buf->buf + buf->cursor));
}

static char		*read_til_next_line(int fd, t_buf *buf)
{
	char	*newstr;
	ssize_t	len;

	newstr = NULL;
	while ((len = ft_len_to_endline(fd, buf)) == -1 && buf->size > 0)
	{
		newstr = ft_strnjoin(newstr, buf->buf + buf->cursor,
							buf->size - buf->cursor);
		buf->cursor = buf->size;
	}
	if (buf->size == 0)
		return (newstr);
	else if (buf->size == -1)
		return (NULL);
	newstr = ft_strnjoin(newstr, buf->buf + buf->cursor, len);
	if (newstr == NULL)
		return (NULL);
	buf->cursor += len + 1;
	return (newstr);
}

static t_list	*bufnew(t_list **list, int fd)
{
	t_buf	*buf;
	t_list	*cur;

	buf = (t_buf*)malloc(sizeof(t_buf));
	if (buf == NULL)
		return (NULL);
	buf->fd = fd;
	buf->size = 0;
	buf->cursor = 0;
	ft_bzero(buf->buf, sizeof(buf->buf));
	cur = ft_lstnew(NULL, 0);
	if (cur == NULL)
	{
		free(buf);
		return (NULL);
	}
	cur->content = buf;
	cur->content_size = sizeof(t_buf);
	ft_lstadd(list, cur);
	return (cur);
}

static t_list	*find_buf(t_list *lst, int fd)
{
	while (lst != NULL && ((t_buf*)lst->content)->fd != fd)
		lst = lst->next;
	return (lst);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*tree;
	t_buf			*buf;
	t_list			*cur;
	char			*tmpline;

	if (line == NULL)
		return (-1);
	cur = find_buf(tree, fd);
	if (cur == NULL && (cur = bufnew(&tree, fd)) == NULL)
		return (-1);
	buf = cur->content;
	if ((tmpline = read_til_next_line(fd, buf)) == NULL)
		if (buf->size == 0)
			return (0);
		else
			return (-1);
	else
	{
		*line = tmpline;
		return (1);
	}
}
