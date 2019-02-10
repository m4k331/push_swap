/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:23:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/10 12:04:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
/*
static void	swap_ascending(t_list **stack, int sz)
{
	swap_stack(stack);
	if (stack_ascending(*stack, sz))
		return ;
	swap_stack(stack);
}
*/
/*
int			partition_ascending(t_list **a, t_list **b, int sz)
{
	int		iter;
	int		rot;
	int		put;
	int		pivot;

	if (sz == 0 || sz == 1 || stack_ascending(*a, sz))
		return (0);
	rot = 0;
	put = 0;
	iter = sz + 1;
	pivot = get_median(*a, sz);
	while (--iter)
		if (!stack_ascending(*a, sz - put) || *(int*)(*a)->content < pivot)
		{
			if (iter == 2 || iter == 3)
				swap_ascending(a, ins, sz);
			if (*(int*)(*a)->content < pivot && ++put)
				put_stack(b, a);
			else if (++rot)
				rotate_stack(a);
		}
	while (rot--)
		rev_rotate_stack(a);
	return (put);
}
*/
static void	swap_descending(t_list **a, t_list **b, t_list **ins, int sz)
{
	ins_swap(ins, a, b, "sb");
	if (stack_descending(*b, sz))
		return ;
	swap_stack(b);
	ft_lstdelnbr(ins, del_content, 0);
}

static int	partition_desc(t_list **a, t_list **b, t_list **ins, int sz)
{
	int		iter;
	int		rot;
	int		put;
	int		pivot;

	if (!sz)
		return (0);
	rot = 0;
	put = 0;
	iter =sz + 1;
	pivot = get_median(*b, sz);
	while (--iter)
	{
		if (!stack_descending(*b, sz) && (iter == 2 || iter == 3))
			swap_descending(a, b, ins, sz);
		if ((*b)->content_size >= pivot && ++put)
			ins_put(ins, a, b, "pa");
		else if (++rot)
			ins_rotate(ins, a, b, "rb");
	}
	while (rot--)
		ins_rev_rotate(ins, a, b, "rrb");
	return (put);
}
/*
static int	right_sort(t_list **a, t_list **b, int sz)
{
	int		put;

	put = partition_ascending(a, b, sz);
	sz -= put;
	if (!stack_ascending(*a, sz))
		put += right_sort(a, b, sz);
	return (put);
}
*/
static void	in_sort(t_list **a, t_list **b, t_list **ins, int sz, int sz_part)
{
	int		put;

	if (!sz || sz <= sz_part)
		in_mid(a, b, ins, sz);
	else
	{
		put = partition_desc(a, b, ins, sz);
		in_descending(a, b, ins, sz);
	//	sz -= put;
	//	if (stack_ascending(*a, put) && stack_descending(*b, sz))
	//		left_sort(a, b, sz);
	//	else
	//		left_sort(a, b, sz + right_sort(a, b, put));
	}
}



void		quick_sort(t_list **a, t_list **b, t_list **ins, int sz_part)
{
	int		sz;
	int		pivot;
	int		i;
	int		put;

	put = 0;
	sz = *a ? ft_lstsize(*a) : 0;
	pivot = get_median(*a, sz);
	if (!(i = sz) || !sz_part || stack_ascending(*a, sz))
		return ;
	if (sz <= sz_part)
		sz < 6 ? bt_ascending(a, ins, sz) : in_ascending(a, ins, sz);
	while (!stack_ascending(*a, sz - put) && i--)
	{
		if (stack_ascending(*a, sz - put) && (*a)->content_size >= pivot)
			break ;
		if ((*a)->content_size < pivot && ++put)
			ins_put(ins, a, b, "pb");
		else
			ins_rotate(ins, a, b, "ra");
	}
	if (!stack_ascending(*a, sz - put))
		quick_sort(a, b, ins, sz_part);
	in_sort(a, b, ins, put, sz_part);
}
