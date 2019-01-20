/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:11:13 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/20 16:47:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# define STACK_SIZE 8192
# include "../libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_vector
{
	char			*con;
	size_t			fd;
	size_t			st;
	size_t			hd;
	size_t			sz;
}					t_vector;

#endif
