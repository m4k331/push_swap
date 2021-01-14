/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:24:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 20:34:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** The function parses the args array
** if finds the flag -f reads the numbers from the file,
** if the function does not find the flag,
** then the parses arguments and the result write in struct ps.
** In case of invalid input, the function clears the stack and return -1
*/

int					parse_nums(t_ps *ps, char flag, int *ac, char ***av)
{
	t_vector		*v;
	int				fd;
	int				err;

	fd = -1;
	err = -1;
	if (flag & 1)
	{
		if ((fd = open(**av, O_RDONLY)) != -1)
		{
			(*av)++;
			(*ac)--;
			if ((v = ft_vnew(BUFF_SIZE, 1)))
			{
				if (ft_vreadfile(v, fd, BUFF_SIZE) != -1)
					err = fill_stack(&ps->a, (char**)&v->con, 1);
				ft_vdel(&v);
			}
			close(fd);
		}
	}
	else
		err = fill_stack(&ps->a, *av, *ac);
	return (err);
}
