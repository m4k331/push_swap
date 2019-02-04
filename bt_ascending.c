/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_ascending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:32:25 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 12:51:00 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int		apply_ins(t_list **stack, t_list **ins, int index)
{
	int			state;

	state = 0;
	if (*stack)
	{
		if (index == 0)
			state = ins_swap(ins, stack, 0, "sa");
		else if (index == 1)
			state = ins_rotate(ins, stack, 0, "ra");
		else if (index == 2)
			state = ins_rev_rotate(ins, stack, 0, "rra");
	}
	return (state);
}

static void		cancel_ins(t_list **stack, t_list **ins)
{
	char		*con;

	con = 0;
	if (*ins)
	{
		con = (char*)(*ins)->content;
		if (con[0] == 's')
			swap_stack(stack);
		else if (con[1] == 'a')
			rev_rotate_stack(stack);
		else
			rotate_stack(stack);
		ft_lstdelnbr(ins, del_content, 0);
	}
}

static t_list	*bck_trck(t_list **stack, t_list **ins, size_t size, int iter)
{
	t_list		*res;
	int			index;

	res = *ins;
	index = 0;
	if (stack_ascending(*stack, size))
		return (res);
	while (iter && index < 3)
	{
		if (!(apply_ins(stack, ins, index)))
		{
			if (*ins)
				ft_lstdel(ins, del_content);
			if (*stack)
				ft_lstdel(stack, del_content);
			return (0);
		}
		if ((res = bck_trck(stack, ins, size, iter - 1)))
			return (res);
		else
			cancel_ins(stack, ins);
		index++;
	}
	return (0);
}

void		bt_ascending(t_list **stack, t_list **ins, size_t size)
{
	t_list	*new;
	int		iter;

	iter = 1;
	new = 0;
	while (!(stack_ascending(*stack, size)))
		bck_trck(stack, &new, size, iter++);
	ft_lstrev(&new);
	*ins = ft_lstjoin(new, *ins);
}
