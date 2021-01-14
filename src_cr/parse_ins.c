/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:45:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 23:11:51 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** The function parses the instructions
** if finds the flag -f reads the numbers from the file,
** if the function does not find the flag,
** then the parses stdin and the result write in struct ps.
*/

void			parse_ins(t_ps *ps, char flag, char **av)
{
	t_vector	*v;
	int			fd;

	fd = (flag & 1) ? open(*av, O_RDONLY) : 0;
	if ((v = ft_vnew(BUFF_SIZE, 1)))
	{
		if (ft_vreadfile(v, fd, BUFF_SIZE) != -1)
			ps->err = fill_ins(&ps->ins, v->con);
		ft_vdel(&v);
	}
	if (close(fd) == -1)
		ps->err = 1;
}
