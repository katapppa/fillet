/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:23:12 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/09 19:00:14 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	int c;
	int fig;

	c = 0;
	fig = 0;
	if (argc == 1)
	{
		printf("ASHIBKAA");
		return (0);
	}
	if (argc > 2)
	{
		printf("oshibka");
		return (0);
	}
	//printf("%d",argc);
	//printf("%s", argv[1]);
	fd = open(argv[1], O_RDONLY);
	
	while(get_next_line(fd,&line) > 0)
	{
		i = 0;
		//printf("%c\n",line[0]);
		while (line[i] == '.' || line[i] == '#')
		{
			if (line[i] == '#')
				fig++;
			i++;
		}
		c++;
		printf("%d",i);
		if (c == 4 && fig != 4)
			printf("Koshibke");
		if (c == 5 && line[0] != '\0')
		{
			printf("Oshibka");
			c = 0;
		}
		else if (c == 5 && line[0] == '\0')
		{	
			c = 0;
			fig = 0;
			i = 4;
		}
		printf("%d",c);
		if (i != 4 )
			printf("Oshibka");
		printf("%s\n",line);
	}
	//printf("Lelele");
	return (1);
}