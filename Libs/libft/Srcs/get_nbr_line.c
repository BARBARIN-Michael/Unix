/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:54:21 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:52:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		get_nbr_line(char *file)
{
	int		fd;
	int		rslt;
	char	*buf;
	int		cmp;

	rslt = 1;
	fd = open(file, O_RDONLY);
	buf = malloc(BUFF_SIZE + 1);
	cmp = 0;
	while (rslt > 0)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((rslt = read(fd, buf, BUFF_SIZE)) > 0)
			cmp += ft_count_carac(buf, '\n');
	}
	free(buf);
	if (rslt < 0)
		return (-1);
	close(fd);
	return (cmp);
}
