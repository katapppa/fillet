/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:32:29 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/22 19:36:42 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map(t_fig *figurs, int j)
{
	t_mp	*mepa;
	int		size;

	size = j;
	mepa = crmap(size * 2);
	while(!solve(mepa, figurs, size))
	{
		free_map(mepa, size);
		size++;
		mepa = crmap(size);
	}
	//printmep();
	free_map(mepa, size);
}

int		solve(t_mp *mepa, t_fig *figurs, int size)
{
	while(vpihevaem());
}