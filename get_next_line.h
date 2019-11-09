/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:13:39 by cgamora           #+#    #+#             */
/*   Updated: 2019/11/09 19:00:18 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 44

typedef struct		s_lest
{
	int				fd;
	char			*ost;
	struct s_lest	*next;
}					t_lest;

int					get_next_line(const int fd, char **line);
//int					main(int argc, char **argv);
#endif
