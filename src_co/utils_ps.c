/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:19:35 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 21:01:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_ps		*get_newps(t_list *a, t_list *b, t_list *ins)
{
	t_ps	*ps;

	if ((ps = (t_ps*)malloc(sizeof(t_ps))))
	{
		ps->a = a;
		ps->b = b;
		ps->ins = ins;
		ps->index = 1;
		ps->err = 1;
	}
	return (ps);
}

void		del_ps(t_ps *ps)
{
	if (ps)
	{
		if (ps->a)
			ft_lstdel(&ps->a, del_content);
		if (ps->b)
			ft_lstdel(&ps->b, del_content);
		if (ps->ins)
			ft_lstdel(&ps->ins, del_content);
		ft_memdel((void**)&ps);
	}
}
