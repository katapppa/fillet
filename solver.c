/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:29 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/25 19:07:50 by cgamora          ###   ########.fr       */
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
	while(i < 8)
	{
		y = figurs->coord[i + 1] + figurs->smesh_y;
		x = figurs->coord[i] + figurs->smesh_x; 
		mepa->map[y][x] = letter;
		i += 2;
	}
}

int		grfig(t_mp *mepa, t_fig *figurs)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	y = figurs->coord[i + 1] + figurs->smesh_y;
	x = figurs->coord[i] + figurs->smesh_x;
	while (i < 7 && mepa->map[y][x] == '.')
	{
		i += 2;
		y = figurs->coord[i + 1] + figurs->smesh_y;
		x = figurs->coord[i] + figurs->smesh_x;
	}
	return (i != 8);
}

int		provmap(t_fig *figurs, int size, char bukva)
{
	if (bukva == 'x')
		return (figurs->coord[1] + figurs->smesh_y < size && figurs->coord[3] + figurs->smesh_y < size &&
		figurs->coord[5] + figurs->smesh_y < size && figurs->coord[7] + figurs->smesh_y < size);
	else
		return (figurs->coord[0] + figurs->smesh_x < size && figurs->coord[2] + figurs->smesh_x < size &&
		figurs->coord[4] + figurs->smesh_x < size && figurs->coord[6] + figurs->smesh_x < size);
}

int		solve(t_mp *mepa, t_fig *figurs, int size)
{
	if(!figurs)
		return (1);
	figurs->smesh_x = 0;
	figurs->smesh_y = 0;
	while (provmap(figurs, size, 'x'))
	{
		while (provmap(figurs, size, 'y'))
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