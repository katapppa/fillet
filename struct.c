/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:18 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/22 18:40:26 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_mp *map, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}


int		crmap(int size)
{
	t_mp	*mep;
	char	i;

	i = 0;
	mep = (t_mp*)malloc(sizeof(t_mp));
	if (mep == NULL)
		return (0);
	mep->map = (char**)malloc(sizeof(char*) * size);
	while (i < size)
	{
		mep->map[i] = ft_strnew(size);
		ft_memset(mep->map[i], '.', size);
		i++;
	}
	return(0);
}

int		korlist(char **buf, int size)
{
	static t_fig	*first;
	t_fig			*figurs;
	int				i;
	char			letters;

	letters = 'A';
	i = 0;
	while (i <= size)
	{
		if (letters == 'A')
		{
			first = korzap(buf, i, letters);
			printf("%c\n", first->letter);
			printf("[%d, ", first->coord[0]);
			printf("%d]\n", first->coord[1]);
			printf("[%d, ", first->coord[2]);
			printf("%d]\n", first->coord[3]);
			printf("[%d, ", first->coord[4]);
			printf("%d]\n", first->coord[5]);
			printf("[%d, ", first->coord[6]);
			printf("%d]\n", first->coord[7]);
			printf ("\n");
			figurs = first;
		}
		else
		{
			figurs->next = korzap(buf, i, letters);
			figurs = figurs->next;
			printf("%c\n", figurs->letter);
			printf("[%d, ", figurs->coord[0]);
			printf("%d]\n", figurs->coord[1]);
			printf("[%d, ", figurs->coord[2]);
			printf("%d]\n", figurs->coord[3]);
			printf("[%d, ", figurs->coord[4]);
			printf("%d]\n", figurs->coord[5]);
			printf("[%d, ", figurs->coord[6]);
			printf("%d]\n", figurs->coord[7]);
			printf ("\n");
		}
		i++;
		letters++;
	}
	figurs->next = NULL;
	return (0);
}



t_fig	*sort(t_fig *figurs)
{
	while (figurs->coord[0] != 0 && figurs->coord[2] != 0 && figurs->coord[4] != 0 && figurs->coord[6] != 0)
	{
		figurs->coord[0] -= 1;
		figurs->coord[2] -= 1;
		figurs->coord[4] -= 1;
		figurs->coord[6] -= 1;
	}
	while (figurs->coord[1] != 0 && figurs->coord[3] != 0 && figurs->coord[5] != 0 && figurs->coord[7] != 0)
	{
		figurs->coord[1] -= 1;
		figurs->coord[3] -= 1;
		figurs->coord[5] -= 1;
		figurs->coord[7] -= 1;
	}
	return (figurs);
}

t_fig	*korzap(char	**buf, int j, char letters)
{
	t_fig			*figurs;
	int				x;
	int				y;
	int				i;

	x = 0;
	i = 0;
	y = 1;
	figurs = (t_fig*)malloc(sizeof(t_fig));
	if (figurs == NULL)
		return (0);
	while (i < 16)
	{
		if (buf[j][i] == '#')
		{
			figurs->coord[x] = (i >= 4) ? (i%4) : i;
			figurs->coord[y] = (i/4);
			figurs->letter = letters;
			x = x + 2;
			y = y + 2;
		}
		i++;
	}
	figurs->smesh_x = 0;
	figurs->smesh_y = 0;
	return (sort(figurs));
}