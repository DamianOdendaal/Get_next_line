/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:00:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/09 16:15:57 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_newlr(char **line, char **s)
{
	char	*str;
	char	*temp;
	int	len;

	len = 0;
	str = (char*)*s;
	while ((str[len] != '\n') && (str[len] != '\0'))
		len++;

	if (str[len] == '\n')
	{
		*line = ft_strsub(str, 0 ,len);
		temp = ft_strdup(&str[len + 1]);
		*s = temp;
		if (s[0] == '\0')
			ft_strdel(&*s);
		return (1);
	}
	if (str[len] == '\0')
	{
		*line = ft_strdup(str);
		ft_strdel(s);
		return (1);
	}
	return (0);
}

static int		ft_bread(const int fd, char **s, char *buff, int *readb)
{
	char		*tvar;
	
	while (*readb > 0)
	{
		buff[*readb] = '\0';
		tvar = ft_strjoin(*s, buff);
		*s = tvar;
		ft_putendl(tvar);
		if (ft_strchr(buff, '\n'))
			break ;
		*readb = read(fd, buff, BUFF_SIZE);
	}
	return (*readb);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		buff[BUFF_SIZE + 1];
	int		readb;

	if(!line || read(fd, NULL, 0) == -1)
		return (-1);
	buff = ft_strnew(BUFF_SIZE + 1);
	readb = read(fd, buff, BUFF_SIZE);
	buff[readb] = '\0';
	if (readb > 0)
		ft_bread(fd, &s, buff, &readb);

	if (s == NULL)
	{
		if (readb == 0)
			*line = ft_strdup("");
		return (0);
	}
	ft_strdel(&buff);
		return (ft_newlr(line, &s));
}
