/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:44:56 by ahallain          #+#    #+#             */
/*   Updated: 2021/02/20 19:41:17 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"

#ifndef BUFFERSIZE
# define BUFFERSIZE 32
#endif

bool	gnl_check(int fd, char **buf, char **sav)
{
	if (BUFFERSIZE <= 0)
		return (1);
	if (fd < 0)
		return (1);
	if (!(*buf = malloc(sizeof(char *) * (BUFFERSIZE + 1))))
		return (1);
	if (!*sav)
	{
		if (!(*sav = malloc(sizeof(char *))))
			return (1);
		**sav = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*sav[PATH_MAX];
	char		*buf;
	ssize_t		ret;
	bool		includes;

	if (gnl_check(fd, &buf, &sav[fd]))
		return (-1);
	ret = 0;
	while (!(includes = ft_contain(sav[fd], '\n'))
		&& (ret = read(fd, buf, BUFFERSIZE)) > 0)
	{
		buf[ret] = 0;
		ft_addstr(buf, &sav[fd]);
	}
	free(buf);
	if (ret != -1)
		ret = includes;
	*line = ft_getstr(sav[fd], '\n');
	ft_rmfirst(&sav[fd], ft_strlen(sav[fd], '\n') + includes);
	if (!ret || !*sav[fd])
	{
		free(sav[fd]);
		sav[fd] = 0;
	}
	return (ret);
}
