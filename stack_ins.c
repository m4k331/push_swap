/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:29:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 12:45:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			ins_swap(t_list **ins, t_list **a, t_list **b, char *in)
{
	t_list	*new;

	if (in[1] == 'a' || in[1] == 's')
		swap_stack(a);
	if (in[1] == 'b' || in[1] == 's')
		swap_stack(b);
	if ((new = ft_lstnew(in, 3)))
		ft_lstadd(ins, new);
	else
		return (0);
	return (1);
}

int			ins_put(t_list **ins, t_list **a, t_list **b, char *in)
{
	t_list	*new;

	if (in[1] == 'a')
		put_stack(a, b);
	if (in[1] == 'b')
		put_stack(b, a);
	if ((new = ft_lstnew(in, 3)))
		ft_lstadd(ins, new);
	else
		return (0);
	return (1);
}

int			ins_rotate(t_list **ins, t_list **a, t_list **b, char *in)
{
	t_list	*new;

	if (in[1] == 'a' || in[1] == 'r')
		rotate_stack(a);
	if (in[1] == 'b' || in[1] == 'r')
		rotate_stack(b);
	if ((new = ft_lstnew(in, 3)))
		ft_lstadd(ins, new);
	else
		return (0);
	return (1);
}

int			ins_rev_rotate(t_list **ins, t_list **a, t_list **b, char *in)
{
	t_list	*new;

	if (in[2] == 'a' || in[2] == 'r')
		rev_rotate_stack(a);
	if (in[2] == 'b' || in[2] == 'r')
		rev_rotate_stack(b);
	if ((new = ft_lstnew(in, 4)))
		ft_lstadd(ins, new);
	else
		return (0);
	return (1);
}
