/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:46:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:57:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** The function finds a pair in sequence of ra && rb instructions
** and replaces them with rr. If successful, return 1, otherwise 0.
*/

static int			ra(t_ps *ps, t_list *crr, int del)
{
	t_list			*head;

	head = crr;
	if (!ft_strcmp(crr->content, "ra"))
		while ((crr = crr->next))
		{
			del++;
			if (!ft_strcmp(crr->content, "rb"))
			{
				((char*)(head->content))[1] = 'r';
				ft_lstdelnbr(&ps->ins, del_content, del);
				return (1);
			}
			else if (ft_strcmp(crr->content, "rra") && \
					ft_strcmp(crr->content, "ra") && \
					ft_strcmp(crr->content, "sa"))
				return (0);
		}
	return (0);
}

/*
** The function finds a pair in sequence of rb && ra instructions
** and replaces them with rr. If successful, return 1, otherwise 0.
*/

static int			rb(t_ps *ps, t_list *crr, int del)
{
	t_list			*head;

	head = crr;
	if (!ft_strcmp(crr->content, "rb"))
		while ((crr = crr->next))
		{
			del++;
			if (!ft_strcmp(crr->content, "ra"))
			{
				((char*)(head->content))[1] = 'r';
				ft_lstdelnbr(&ps->ins, del_content, del);
				return (1);
			}
			else if (ft_strcmp(crr->content, "rrb") && \
					ft_strcmp(crr->content, "rb") && \
					ft_strcmp(crr->content, "sb"))
				return (0);
		}
	return (0);
}

/*
** Replacing the pair instruction ra && rb on rr
*/

void				rr(t_ps *ps)
{
	t_list			*crr;
	int				del;

	crr = ps->ins;
	del = 0;
	while (crr)
		if (ra(ps, crr, del) || rb(ps, crr, del))
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
