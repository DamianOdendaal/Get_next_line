/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:00:39 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/04 17:38:24 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static void	ft_read_a_line(int fd, char **fd_arr) */
/* { */
/* 	set a buffer[BUFF_SIZE + 1] */
/* 	set a ret */

	/* if(fd_arr[fd] == NULL)		//--------------I know the 1st call of reader, fd_arr[fd] will contain a NULL pointer because I haven't initialised it yet. */
	/* 	fd_arr[fd] = strnew(0); */

/* 	while(strchr(fd_arr[fd], '\n') == NULL) */
/* 	{ */
/* 		ret = read(fd, buffer, BUFF_SIZE); */
/* 		buffer[ret] = '\0'; */
/* 		if(ret == 0 && strlen(ft_arr[fd]) != 0) */
/* 			break; */
/* 		do your storing stuff here by setting fd-arr[fd] to be a strjoin(fd_arr[fd], buffer) */
/* 	} */
/* } */



int	ft_check_and_swap(int fd, char **fd_arr, char **line)
{
			
			do here what we wrote in the book.
			return(1 or 0);
}



int	get_next_line(int fd, char **line)
{
	static char *fd_arr[1024]; //-------------------------------1024 is the max amount of file descriptors unix can have open at the same time
	
	if("do all your error checks here")
		return(-1);

	ft_read_a_line(fd, fd_arr); //----------------------------read from the fd, and store the new line in fd_arr[fd]
	return(ft_check_and_swap(fd, fd_arr, line)); //-----------checks whats in fd_arr[fd]. If there is a '\n' set it to a '\0'.Then set line to the line up until '\0'. then set fd_arr[fd] to what remains after the newly made '\0'.

}




//		tmpcharpointer = strchr(fd_arr_[fd], '\n') + 1;
//		tmp2= ft_strdup(tmpcharpointer);
//		call a memset function to set the '\n' to a '\0'
//		line = strdup(fd_arr[fd]);
//		strdel(fd_arr[fd]);
//		fd_arr[fd] = strdup(tmp2);


int	main(void)
{
	fd = things;
	char *line = NULL;	

	while(get_next_line(fd, lineptr) > 0)
	{
		printf("%s\n", line);
	}
	return(0);
}


char	**name;
name = (char **)malloc(sizeof(char *) * 10);
*name = (char *)malloc(sizeof(char) * 10);

char	name[10][10];

name[5][5] = 'c';

char *ptr = (name + 5);
*(ptr + 5) = 'c'

static char	*array[1025];

array[5] = "aaaaa\naaa";
line = "aaaaa";
array[5] = "aaa";
array[5] = "aaaaaaaa\naa";
line = "aaaaaaaaaa";
array[5] = "aa"
line = "aa"




/*
int get_next_line(int fd, char **line)
{
	static char		*str_temp;
	char			buf;
	int				ret;
	if (!(str_temp = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
}
*/

