/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:00:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/06 00:52:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

if(fd_arr[fd] == NULL)
	fd_arr[fd] = ft_strnew(1);
static void ft_Search_and_replace(char *search, char *replace)
{
 	char *buffer[BUFF_SIZE + 1];
	while (fd_arr[fd] != '\n')
	{
		search = ft_strchr(fd_arr[fd], '\n') + 1;
		temp = ft_memset(fd_arr[fd], '\0', 1);
		line = ft_strdup(fd_arr[fd]);
		ft_strdel(&fd_arr[fd]);
		fd_arr[fd] = ft_strdup(temp);
		len++;
	}
}
	 if (fd_arr[fd] == '\n')
		/* line = ft_strsub(buffer, 0, len); */

/* int get_next_line(int fd, char **line) */
/* { */
/* 	static char		*str_temp[1025]; */
/* 	char			buf; */
/* 	int				ret; */
/* 	if(!line || read(fd, NULL, 0) == -1 ) */
/* 		return(-1); */
/* } */
