/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:29 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/30 20:34:23 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	zapisat(t_mp *mepa, t_fig *figurs, char letter)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while(i < 4)
	{
		y = figurs->coord_y[i] + figurs->smesh_y;
		x = figurs->coord_x[i] + figurs->smesh_x; 
		mepa->map[y][x] = letter;
		i++;
	}
}

int		grfig(t_mp *mepa, t_fig *figurs) //pepe
{
	int x;
	int y;
	int i;
	int f;

	x = 0;
	y = 0;
	i = 0;
	f = 0;
	while (i < 4)
	{
		y = figurs->coord_y[i] + figurs->smesh_y;
		x = figurs->coord_x[i] + figurs->smesh_x;
		if (mepa->map[y][x] == '.')
			f++;
		i++;
	}
	return (f != 4);
}

int		prov_y(t_fig *figurs, int size)
{
		return (figurs->coord_y[0] + figurs->smesh_y < size && figurs->coord_y[1] + figurs->smesh_y < size &&
		figurs->coord_y[2] + figurs->smesh_y < size && figurs->coord_y[3] + figurs->smesh_y < size);
		//return (figurs->coord[0] + figurs->smesh_x < size && figurs->coord[2] + figurs->smesh_x < size &&
		//figurs->coord[4] + figurs->smesh_x < size && figurs->coord[6] + figurs->smesh_x < size);
}

int		prov_x(t_fig *figurs, int size)
{
		return (figurs->coord_x[0] + figurs->smesh_x < size && figurs->coord_x[1] + figurs->smesh_x < size &&
		figurs->coord_x[2] + figurs->smesh_x < size && figurs->coord_x[3] + figurs->smesh_x < size);
		//return (figurs->coord[0] + figurs->smesh_x < size && figurs->coord[2] + figurs->smesh_x < size &&
		//figurs->coord[4] + figurs->smesh_x < size && figurs->coord[6] + figurs->smesh_x < size);
}

int		solve(t_mp *mepa, t_fig *figurs, int size)
{
	if(!figurs)
		return (1);
	figurs->smesh_x = 0;
	figurs->smesh_y = 0;
	while (prov_y(figurs, size))
	{
		while (prov_x(figurs, size))
		{
			if (!grfig(mepa, figurs))
			{
				zapisat (mepa, figurs, figurs->letter);
				if (solve(mepa, figurs->next, size))
					return (1);
				else
				{
					zapisat(mepa, figurs, '.');
				}
			}
			figurs->smesh_x++;
		}
	figurs->smesh_x = 0;
	figurs->smesh_y++;
	}
	return (0);
}

void	map(t_fig *figurs, int j)
{
	t_mp	*mepa;
	int		size;

	size = 1;
	mepa = crmap(size);	
	while(!solve(mepa, figurs, size))
	{
		free_map(mepa, size);
		size++;
		mepa = crmap(size);
	}
	printmep(mepa, size);
	free_map(mepa, size);
}