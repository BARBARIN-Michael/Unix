/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:28:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/20 17:47:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include <libft.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct	s_buf {
	int			fd;
	char		buf[BUFF_SIZE];
	ssize_t		size;
	size_t		cursor;
}				t_buf;
int				get_next_line(int const fd, char **line);
int				get_nbr_line(char *file);
#endif
