/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_papb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:06:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:56:51 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** The function removes two instructions
** Returns 1 if list size > 1, otherwise 0
*/

int					del_two_ins(t_ps *ps, int fdel, int sdel)
{
	ft_lstdelnbr(&ps->ins, del_content, fdel);
	ft_lstdelnbr(&ps->ins, del_content, sdel - 1);
	if (!ft_lstsize(ps->ins))
		return (0);
	return (1);
}

/*
** Removes mutually exclusive instructions pa pb
*/

void				papb(t_ps *ps)
{
	t_list			*ins;
	char			*curr;
	char			*next;
	int				del;

	ins = ps->ins;
	curr = 0;
	next = 0;
	if ((del = 0) || !ins)
		return ;
	while (ins->next)
	{
		curr = (char*)ins->content;
		next = (char*)(ins->next)->content;
		if ((!ft_strcmp(curr, "pa") && !ft_strcmp(next, "pb")) || \
				(!ft_strcmp(curr, "pb") && !ft_strcmp(next, "pa")))
		{
			if (!del_two_ins(ps, del, del + 1))
				break ;
			ins = ps->ins;
			del = 0;
		}
		else if (++del)
			ins = ins->next;
	}
}
