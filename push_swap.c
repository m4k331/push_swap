/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/31 20:55:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack.h"

static int	apply_ins(t_list **stack, t_list **ins, int index)
{
	int		state;

	state = 0;
	if (index == 0)
		state = ins_swap(ins, stack, 0, "sa");
	else if (index == 1)
		state = ins_rotate(ins, stack, 0, "ra");
	else if (index == 2)
		state = ins_rev_rotate(ins, stack, 0, "rra");
	return (state);
}

t_list		*back_tracking(t_list **stack, t_list *ins,  size_t sz , int index)
{
	t_list	*res;

	res = ins;
	printf(">>>\n");
	if (stack_ascending(*stack, sz))
		return (res);
	while (sz && index < 3)
	{
		apply_ins(stack, &ins, index);
		printf("A:  ");print_stack(*stack);printf("\n");
		printf("STACK INS:  ");print_stack_ins(ins);printf("\n");
		if ((res = back_tracking(stack, ins, sz - 1, index)))
			return (res);
		else
		{
			ft_lstdelnbr(&ins, del_content, 0);
			printf("del*A:  ");print_stack(*stack);printf("\n");
			printf("STACK INS:  ");print_stack_ins(ins);printf("\n");
			index++;
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*ins;

	b = 0;
	fill_stack(&a, ++av, --ac);
	printf("A:  ");print_stack(a);printf("\n");
	printf("B:  ");print_stack(b);printf("\n");
	ins = back_tracking(&a, ins, ac, 0);
	printf("STACK INS:  ");print_stack_ins(ins);printf("\n");
	printf("SA:  ");print_stack(a);printf("\n");
	printf("SB:  ");print_stack(b);printf("\n");
	//quick_sort(&a, &b, ac);
	//printf("\nA: ");print_stack(a);printf("\n");
	//printf("B: ");print_stack(b);printf("\n");
	if (is_sorted_stack(a))
		printf("OK\n");
	return (0);
}
