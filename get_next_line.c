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


static int		ft_newls(char **line, char **s)
{
	char		*str;
	char		*temp;
	int			len;

	len = 0;
	str = (char*)*s;
	while ((str[len] != '\n') && (str[len] != '\0'))
		len++;
	if (str[len] == '\n')
	{
		*line = ft_strsub(str, str[0],len);
		temp = ft_strdup(&str[len + 1]);
		*s = temp;
		if (s[0] == '\0')
			ft_strdel(s);
	}
	else if (str[len] == '\0')
	{
		*line = ft_strdup(str);
		ft_strdel(s);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s = NULL;
	char		*buffer;
	int			readb;

	if(!line || read(fd, NULL, 0) == -1 )
		return (-1);
	readb = read(fd, buffer, BUFF_SIZE);
	if (ft_strlen(s) == 0)
	{
		if (readb == 0)
			*line = ft_strdup("");
		return (0);
	}
	ft_strdel(&buffer);
	return (ft_newls(line, &s));
}
