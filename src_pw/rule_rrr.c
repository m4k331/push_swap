/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:32:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:57:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** The function finds a pair in sequence of rra && rrb instructions
** and replaces them with rrr. If successful, return 1, otherwise 0.
*/

static int			rra(t_ps *ps, t_list *crr, int del)
{
	t_list			*head;

	head = crr;
	if (!ft_strcmp(crr->content, "rra"))
		while ((crr = crr->next))
		{
			del++;
			if (!ft_strcmp(crr->content, "rrb"))
			{
				((char*)(head->content))[2] = 'r';
				ft_lstdelnbr(&ps->ins, del_content, del);
				return (1);
			}
			else if (ft_strcmp(crr->content, "rra") && \
					ft_strcmp(crr->content, "ra"))
				return (0);
		}
	return (0);
}

/*
** The function finds a pair in sequence of rrb && rra instructions
** and replaces them with rrr. If successful, return 1, otherwise 0.
*/

static int			rrb(t_ps *ps, t_list *crr, int del)
{
	t_list			*head;

	head = crr;
	if (!ft_strcmp(crr->content, "rrb"))
		while ((crr = crr->next))
		{
			del++;
			if (!ft_strcmp(crr->content, "rra"))
			{
				((char*)(head->content))[2] = 'r';
				ft_lstdelnbr(&ps->ins, del_content, del);
				return (1);
			}
			else if (ft_strcmp(crr->content, "rrb") && \
					ft_strcmp(crr->content, "rb"))
				return (0);
		}
	return (0);
}

/*
** Replacing the pair instruction rra && rrb on rrr
*/

void				rrr(t_ps *ps)
{
	t_list			*crr;
	int				del;

	crr = ps->ins;
	del = 0;
	while (crr)
		if (rra(ps, crr, del) || rrb(ps, crr, del))
		{
			crr = ps->ins;
			del = 0;
		}
		else
		{
			crr = crr->next;
			del++;
		}
}
