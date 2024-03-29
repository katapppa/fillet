/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:23:12 by cgamora           #+#    #+#             */
/*   Updated: 2019/12/02 17:27:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printmep(t_mp *mepa, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		printf("%s\n", mepa->map[i]);
		i++;
	}
}

void	cikl(char *line, int *i, int *fig)
{
	while (line[*i] == '.' || line[*i] == '#')
	{
		if (line[*i] == '#')
			*fig = *fig + 1;
		*i = *i + 1;
	}
}

int		checkn(int fd, char **argv)
{
	char *leni[5 + 1];
	int rb;
	int c;

	c = 0;
	fd = open(argv[1], O_RDONLY);
	while ((rb = read(fd, leni, 5)))
	{
		c += rb;
	}
	close (fd);
	return (c);
}

int		proverka(int fd, char *line, int fig, int i)
{
	int c;
	int f;

	c = 0;
	f = 0;
	while ((f = get_next_line(fd, &line)))
	{
		if (f == 0)
		{
			if (line[0] == '\0' || (c != 0 && c != 4))
			{
				ft_memdel((void**)&line);
				//free(line);
				return (0);
			}
		}
		i = 0;
		cikl(line, &i, &fig);
		c++;
		if ((c == 5 && line[0] != '\0') || (c == 4 && fig != 4))
			return (0);
		if (c == 5 && line[0] == '\0')
		{
			c = 0;
			fig = 0;
			i = 4;
		}
		free(line);
		if (i != 4)
			return (0);
	}
	// if (line[0] == '\0' || (c != 0 && c != 4))
	// {
	// 	//ft_memdel((void**)&line);
	// 	//free(line);
	// 	return (0);
	// }
	close(fd);
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
	line = ft_strnew(0);
	if (argc == 1)
	{
		write(1, "ASHIBKAA", sizeof("ASHIBKAA"));
		return (0);
	}
	if (argc > 2)
	{
		printf("oshibka");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (proverka(fd, line, fig, i))
	{
		ft_memdel((void**)&line);
		if (stroka(fd, line, argv) == 0)
		{
			//free(line);
			printf("OSHIBKA PROVERKI 2");
		}
	}
	else
		printf("OSHIBKA PROVERKI 1");
	close(fd);
	return (1);
}
