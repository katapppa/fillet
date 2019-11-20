/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:36:14 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/20 18:13:48 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		proverka_soseda(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buf[i] != '\0')
	{
		while (buf[i] != '#' && buf[i] != '\0')
			i++;
		if (buf[i] == '\0')
			break ;
		if (buf[i + 1] == '#')
			count++;
		if (buf[i - 1] == '#')
			count++;
		if (buf[i + 4] == '#')
			count++;
		if (buf[i - 4] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		write(1, "chetko\n", sizeof("chetko\n"));
	return (0);
}

int		stroka(int fd, char *line, char **argv)
{
	char	*buf[30];
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < 30)
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
			free(tmp);
			tmp = NULL;
			free(line);
		}
		else
			i++;
		if (i > 26)
			return (0);
	}
	i--;
	while (i >= j)
	{
		printf("STROKA %d: %s\n", j, buf[j]);
		proverka_soseda(buf[j]);
		j++;
	}
	korlist(buf);
	close(fd);
	return (1);
}
