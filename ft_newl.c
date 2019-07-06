/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:45:00 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/06 03:46:29 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_newl(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (*(s + len) != '\n' && *(s + len) != '\0')
	{
		if (*(s + len) == '\n')
		{
			*line = ft_strsub(s, 0, len);
			tmp = ft_strdup(*(s + len) + 1);
			ft_strdel(&s);
			*s = tmp;
		if (*(s + 0) == '\0')
			ft_strdel(&s);
		}
		else if (s[len] == '\0')
		{
			if (ret == BUFF_SIZE)
				return (get_next_line(fd, line));
			*line = ft_strdup(s);
			ft_strdel(&s);
		}
		len++;
	}
	return (1);
}
