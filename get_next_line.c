/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:00:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/10 17:01:33 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int        get_next_line(const int fd, char **line)
 {
     int            eol;
     char        *temp;
     char        buffer[BUFF_SIZE + 1];
     static char    *sc[2147483647];
     ssize_t        t;

     if (fd <= -1 || (!sc[fd] && !(sc[fd] = ft_strnew(1))) || !line)
         return (-1);
     while (!ft_strchr(sc[fd], 10) && (t = read(fd, buffer, BUFF_SIZE)) >= 1)
     {
         buffer[t] = 0;
         temp = sc[fd];
         sc[fd] = ft_strjoin(sc[fd], buffer);
         ft_strdel(&temp);
     }
     if (!*(temp = sc[fd]) || t == -1)
         return (t == -1 ? -1 : 0);
     if ((eol = (ft_strchr(sc[fd], 10) > 0)))
         *line = ft_strsub(sc[fd], 0, ft_strchr(sc[fd], 10) - sc[fd]);
     else
         *line = ft_strdup(sc[fd]);
     sc[fd] = ft_strsub(sc[fd], (unsigned int)(ft_strlen(*line) + eol),
             (size_t)(ft_strlen(sc[fd]) - (eol + ft_strlen(*line))));
     ft_strdel(&temp);
     return (!(!ft_strlen(*line) && !sc[fd]));
 }
