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

static	char	*ft_joiner(char *stat, char *buff)
{
	char	*str;

	str = ft_strjoin(stat, buff);
	free(stat);
	return (str);
}

static	int		ft_readstr(int fd, char **stat)
{
	char	buff[BUFF_SIZE + 1];
	int		res;

	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (stat[fd] == NULL)
			stat[fd] = ft_strdup(buff);
		else
			stat[fd] = ft_joiner(stat[fd], buff);
		if (ft_strchr(stat[fd], '\n'))
			break ;
	}
	return (res);
}

static	int		ft_smover(char **line, char **stat)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*stat)[i] != '\n' && (*stat)[i] != '\0')
		i++;
	if (ft_strchr(*stat, '\n') != NULL)
	{
		*(ft_strchr(*stat, '\n')) = '\0';
		*line = ft_strsub(*stat, 0, i);
		temp = ft_strdup(ft_strchr(*stat, '\0') + 1);
		free(*stat);
		*stat = ft_strdup(temp);
		free(temp);
		if ((*stat)[0] == '\0')
			ft_strdel(stat);
	}
	else
	{
		*line = ft_strdup(*stat);
		ft_strdel(stat);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stat[1024];
	int			res;

	res = 0;
	if (fd < 0 || (read(fd, NULL, 0)) < 0 || !line)
		return (-1);
	res = ft_readstr(fd, stat);
	if (res < 0)
		return (-1);
	if (res == 0 && !stat[fd])
		return (0);
	return (ft_smover(line, &stat[fd]));
}
