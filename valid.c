/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:36:14 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/12 17:15:05 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		proverka_soseda(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(buf[i] != '\0')
	{
		while(buf[i] != '#')
		{
			if(buf[i] == '\0')
			{
				printf("%d\n", count);
				if (count == 6 || count == 8)
					printf("chetko\n");
				return (1);
			}
			i++;
		}
		printf("%c\n", buf[i]);
		if(buf[i + 1] == '#')
			count++;
		if(buf[i - 1] =='#')
			count++;
		if(buf[i + 4] == '#')
			count++;
		if(buf[i - 4] == '#')
			count++;
		i++;
	}
	printf("count: %d\n", count);
	if (count == 6 || count == 8)
		printf("chetko\n");
	return (0);
}

int		stroka(void)
{
	char	*buf[30];
	char 	*line;
	char 	*tmp;	
	int		j;
	int		i;
	int 	fd;

	i = 0;
	j = 0;
	//printf("%c\n",line[0]);
	//buf[i] = ft_strnew(0);
	fd = open("test", O_RDONLY);
	while (i < 30)
	{
		buf[i] = ft_strnew(0);
		i++;
	}
	i = 0;
	while(get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
			tmp = buf[i];
			buf[i] = ft_strjoin(tmp, line);
			free(tmp);
			tmp = NULL;
			free(line);
			//printf("%s\n", buf[i]);
		}
		else
		{
			i++;
			//buf[i] = ft_strnew(0);
		}
		//printf("%d", i);
	}
	while(i>=j)
	{
		printf("STROKA %d: %s\n", j, buf[j]);
		proverka_soseda(buf[j]);
		//free(buf[j]);
		j++;
	}
	close(fd);
	return (1);
}
