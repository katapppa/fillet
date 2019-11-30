/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:36:14 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/30 18:48:57 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		proverka_soseda(char *buf)
{
	int i;
	int count;
	int flag;

	i = 0;
	count = 0;
	while (buf[i] != '\0')
	{
		while (buf[i] != '#' && buf[i] != '\0')
			i++;
		if (buf[i] == '\0')
			break ;
		if (i + 1 < 17 && buf[i + 1] == '#')
			count++;
		if (i - 1 >= 0 && buf[i - 1] == '#')
			count++;
		if (i + 4 < 17 && buf[i + 4] == '#')
			count++;
		if (i - 4 >= 0 && buf[i - 4] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		provern(int fd, char **argv, int i)
{
	int le;

	le = checkn(fd, argv);
	if (le % 2 == 0 && i % 2 == 0)
		return (1);
	else if (le % 2 != 0 && i % 2 != 0)
		return (1);
	else
		return (0);
}

int		stroka(int fd, char *line, char **argv)
{
	char	**buf;
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	buf = (char**)malloc(sizeof(char*)*26);
	fd = open(argv[1], O_RDONLY);
	while (i < 26)
	{
		buf[i] = ft_strnew(0);
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			tmp = buf[i];
			buf[i] = ft_strjoin(tmp, line);
			ft_memdel((void**)&tmp);
			free(line);
		}
		else
		{
			i++;
			ft_memdel((void**)&line);
		}
		if (i > 25)
			return (0);
	}
	close(fd);
	if (provern(fd, argv, i) == 0)
		return (0);
	while (i >= j)
	{
		if (proverka_soseda(buf[j]) == 0)
			return (0);
		j++;
	}
	korlist(buf, i);
	i = 0;
	while (i <= 25)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return (1);
}
