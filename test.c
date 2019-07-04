
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	**array;
	array = (char **)malloc(sizeof(char *) * (10 + 1));
	char	name[10][10] = { "aaaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa"};

	char	*ptr;

	

	int i = 0;
	int j = 0;
	*(array + 10) = NULL;

	while (i < 10)
	{
		*(array + i) = (char *)malloc(sizeof(char) * (10 + 1));
		ptr = *(array + i);
		*(ptr + 10) = '\0';
		i++;
	}

	

	/* i = 0; */
	/* j = 0; */
	/* while (i < 10) */
	/* { */
	/* 	j = 0; */
	/* 	while (j < 10) */
	/* 	{ */
	/* 		name[i][j] = 'a'; */
	/* 		j++; */
	/* 	} */
	/* 	i++; */
	/* } */

	i = 0;
	j = 0;
	while ( i < 10)
	{
		j = 0;
		ptr = *(array + i);
		while(j < 10)
		{
			*(ptr + j) = 'a';
			j++;
		}
		i++;
	}

	

	name[5][5] = 'c';
	ptr = *(array + 5);
	*(ptr + 5) = 'c';

	

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		printf("name[%d]%s\n",i, name[i]);
		while (j < 10)
		{
			/* printf("name[%d][%d]%c\n", i, j,name[i][j]); */
			j++;
		}
		i++;
	}

	

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		ptr = *(array + i);
		printf("array[%d]%s\n", i,  ptr);
		while (j < 10)
		{
			/* printf("array[%d][%d]%c\n", i, j,*(ptr + j)); */
			j++;
		}
		i++;
	}

	
	return(0);
}
