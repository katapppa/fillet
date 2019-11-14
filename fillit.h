/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:40:21 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/14 20:52:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

int		proverka(int fd, char *line, int fig, int i);
int		proverka_soseda(char *buf);
int		stroka(int fd, char *line, char **argv);
void	cikl(char *line, int *i, int *fig);

#endif
