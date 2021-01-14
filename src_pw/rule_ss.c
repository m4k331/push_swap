/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:54:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:57:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Replacing the pair instruction (sa && sb) || (sb && sa) on ss
*/

void				ss(t_ps *ps)
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
		if ((!ft_strcmp(curr, "sa") && !ft_strcmp(next, "sb")) || \
				(!ft_strcmp(curr, "sb") && !ft_strcmp(next, "sa")))
		{
			curr[1] = 's';
			ft_lstdelnbr(&ps->ins, del_content, del + 1);
			ins = ps->ins;
			del = 0;
		}
		else if (++del)
			ins = ins->next;
	}
}
