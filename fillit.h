/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:40:21 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/21 19:10:18 by cgamora          ###   ########.fr       */
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
	int				coord[8];
	char			letter;
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

#endif
