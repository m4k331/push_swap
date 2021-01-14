/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:11:13 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/30 12:06:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# define STACK_SIZE 8192
# include "libft.h"

typedef struct		s_vec
{
	char			*con;
	size_t			fd;
	size_t			st;
	size_t			hd;
	size_t			sz;
}					t_vec;

int					get_next_line(const int fd, char **line);

#endif
