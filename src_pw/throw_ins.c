/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:12:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:57:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Upon successful completion, a value of 0 is returned.
** Otherwise, a value of -1 is returned
*/

int					throw_ins(t_ps *ps, char flag, int ac, char **av)
{
	int				fd;

	fd = 1;
	modify_instruction(ps);
	if (flag & 1 && ac == 1 && (fd = open(*av, O_CREAT | O_WRONLY, 0666)) != -1)
	{
		print_stack_ins(ps->ins, fd);
		if (close(fd) == -1)
			return (-1);
	}
	else
		print_stack_ins(ps->ins, 1);
	return (0);
}
