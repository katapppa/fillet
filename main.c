/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:23:12 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/12 18:54:28 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		provif(char *line, int c, int fig)
{
	if ((c == 5 && line[0] != '\0') || (c == 4 && fig != 4))
		return (0);
	return (1);
}

int		proverka(int fd, char *line, int fig, int i)
{
	int c;

	c = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] == '.' || line[i] == '#')
		{
			if (line[i] == '#')
				fig++;
			i++;
		}
		c++;
		if ((c == 5 && line[0] != '\0') || (c == 4 && fig != 4))
			return (0);
		if (c == 5 && line[0] == '\0')
		{
			c = 0;
			fig = 0;
			i = 4;
		}
		if (i != 4)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fig;
	int		i;
	int		fd;
	char	*line;

	fig = 0;
	i = 0;
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
	fd = open(argv[1], O_RDONLY);
	if(proverka(fd, line, fig, i))
	{
		if(stroka() == 0)
			printf("OSHIBKA PROVERKI 2");
	}
	else 
		printf("OSHIBKA PROVERKI 1");
	return (1);
}
