/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rarra_rbrrb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:10:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:56:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Returns the index of the instruction ra following the rra otherwise returns 0
*/

static int			pos_rrara(t_list *ins, char *pattern)
{
	int				index;
	int				rra;

	index = 0;
	rra = !ft_strcmp(pattern, "rra");
	if (ins)
		while ((ins = ins->next))
		{
			index++;
			if (!ft_strcmp(ins->content, "pa") || !ft_strcmp(ins->content, "pb")
				|| !ft_strcmp(ins->content, "sa") \
				|| !ft_strcmp(ins->content, pattern))
				return (0);
			if (rra && !ft_strcmp(ins->content, "ra"))
				return (index);
			if (!rra && !ft_strcmp(ins->content, "rra"))
				return (index);
		}
	return (0);
}

/*
** Returns the index of the instruction rb following the rrb otherwise returns 0
*/

static int			pos_rrbrb(t_list *ins, char *pattern)
{
	int				index;
	int				rrb;

	index = 0;
	rrb = !ft_strcmp(pattern, "rrb");
	if (ins)
		while ((ins = ins->next))
		{
			index++;
			if (!ft_strcmp(ins->content, "pa") || !ft_strcmp(ins->content, "pb")
				|| !ft_strcmp(ins->content, "sb") \
				|| !ft_strcmp(ins->content, pattern))
				return (0);
			if (rrb && !ft_strcmp(ins->content, "rb"))
				return (index);
			if (!rrb && !ft_strcmp(ins->content, "rrb"))
				return (index);
		}
	return (0);
}

/*
** The function checks the sequence of instructions ra -> rra or rra > ra
** excluding instructions that do not contradict them.
** In case of successful finding of the sequence deletes this pair of ins
** and returns 1, otherwise 0.
*/

static inline int	rarra(t_ps *ps, t_list *crr, int fdel)
{
	int				sdel;

	sdel = 0;
	if (!ft_strcmp(crr->content, "ra") && (sdel = pos_rrara(crr, "ra")))
		return (del_two_ins(ps, fdel, fdel + sdel));
	else if (!ft_strcmp(crr->content, "rra") && (sdel = pos_rrara(crr, "rra")))
		return (del_two_ins(ps, fdel, fdel + sdel));
	return (0);
}

/*
** The function checks the sequence of instructions rb -> rrb or rrb > rb
** excluding instructions that do not contradict them.
** In case of successful finding of the sequence deletes this pair of ins
** and returns 1, otherwise 0.
*/

static inline int	rbrrb(t_ps *ps, t_list *crr, int fdel)
{
	int				sdel;

	sdel = 0;
	if (!ft_strcmp(crr->content, "rb") && (sdel = pos_rrbrb(crr, "rb")))
		return (del_two_ins(ps, fdel, fdel + sdel));
	else if (!ft_strcmp(crr->content, "rrb") && (sdel = pos_rrbrb(crr, "rrb")))
		return (del_two_ins(ps, fdel, fdel + sdel));
	return (0);
}

/*
** Removes mutually exclusive instructions (ra && rra) || (rb && rrb)
*/

void				rarra_rbrrb(t_ps *ps)
{
	t_list			*crr;
	int				fdel;

	crr = ps->ins;
	fdel = 0;
	while (crr)
		if (rarra(ps, crr, fdel) || rbrrb(ps, crr, fdel))
		{
			crr = ps->ins;
			fdel = 0;
		}
		else
		{
			crr = crr->next;
			fdel++;
		}
}
