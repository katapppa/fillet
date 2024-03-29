/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:18 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/30 20:34:20 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_mp *mep, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(mep->map[i]));
		i++;
	}
	ft_memdel((void **)&(mep->map));
	ft_memdel((void **)&mep);
}


t_mp	*crmap(int size)
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
	return (mep);
}

void	free_fig(t_fig *tmp)
{
	if (tmp->next)
		free_fig(tmp->next);
	free(tmp);
}

int		korlist(char **buf, int size)
{
	t_fig			*first;
	t_fig			*figurs;
	t_fig			*tmp;
	int				i;
	char			letters;

	letters = 'A';
	i = 0;
	while (i <= size)
	{
		if (letters == 'A')
		{
			first = korzap(buf, i, letters);
			figurs = first;
			tmp = first;
		}
		else
		{
			figurs->next = korzap(buf, i, letters);
			figurs = figurs->next;
		}
		i++;
		letters++;
	}
	figurs->next = NULL;
	map(first, size);
	free_fig(tmp);
	return (0);
}



t_fig	*sort(t_fig *figurs)
{
	while (figurs->coord_x[0] != 0 && figurs->coord_x[1] != 0 && figurs->coord_x[2] != 0 && figurs->coord_x[3] != 0)
	{
		figurs->coord_x[0] -= 1;
		figurs->coord_x[1] -= 1;
		figurs->coord_x[2] -= 1;
		figurs->coord_x[3] -= 1;
	}
	while (figurs->coord_y[0] != 0 && figurs->coord_y[1] != 0 && figurs->coord_y[2] != 0 && figurs->coord_y[3] != 0)
	{
		figurs->coord_y[0] -= 1;
		figurs->coord_y[1] -= 1;
		figurs->coord_y[2] -= 1;
		figurs->coord_y[3] -= 1;
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
	y = 0;
	figurs = (t_fig*)malloc(sizeof(t_fig));
	if (figurs == NULL)
		return (0);
	while (i < 16)
	{
		if (buf[j][i] == '#')
		{
			figurs->coord_x[x] = (i >= 4) ? (i%4) : i;
			figurs->coord_y[y] = (i/4);
			figurs->letter = letters;
			x++;
			y++;
		}
		i++;
	}
	figurs->smesh_x = 0;
	figurs->smesh_y = 0;
	return (sort(figurs));
}