/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:40:21 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/30 18:24:32 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct	s_figura
{
	int				coord_x[4];
	int				coord_y[4];
	char			letter;
	int				smesh_x;
	int				smesh_y;
	struct s_figura	*next;
}				t_fig;

typedef struct	s_map
{
	char	**map;	
}				t_mp;

int		proverka(int fd, char *line, int fig, int i);
int		proverka_soseda(char *buf);
int		stroka(int fd, char *line, char **argv);
void	cikl(char *line, int *i, int *fig);
t_fig	*korzap(char	**buf, int j, char letter);
int		korlist(char **buf, int size);
t_fig	*sort(t_fig *figurs);
int		checkn(int fd, char **argv);
int		provern(int fd, char **argv, int i);
t_mp	*crmap(int size);
void	free_map(t_mp *mep, int size);
void	printmep(t_mp *mepa, int size);
void	map(t_fig *figurs, int j);

#endif
