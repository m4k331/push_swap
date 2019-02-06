/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/06 21:49:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int			count_elems_asc(t_list *stack, int size)
{
	t_list	*next;
	int		count;

	next = 0;
	count = 0;
	if (stack && (next = stack->next))
		while (next && size && *(int*)stack->content < *(int*)next->content)
		{
			stack = next;
			next = stack->next;
			count++;
			size--;
		}
	return (count);
}

int			get_val_index(t_list *stack, int index)
{
	while (stack->content_size != index)
		stack = stack->next;
	return (*(int*)stack->content);
}

size_t		get_max_index(t_list *stack, int size)
{
	size_t	index;

	index = 0;
	while (stack)
	{
		if (index < stack->content_size)
			index = stack->content_size;
		stack = stack->next;
	}
	return (index);
}

int			get_pos(t_list *stack, int index)
{
	int		pos;

	pos = 0;
	if (index > 0)
		while (stack && ++pos && stack->content_size != index)
			stack = stack->next;
	return (pos);
}




void		in_ascending(t_list **stack, t_list **ins, int size)
{
	size_t	wall;
	size_t	curr;

	wall = get_max_index(*stack, size) - 1;
	curr = wall - 1;
	if (*stack)
	{
		while (!stack_ascending(*stack, size))
			if (get_pos(*stack, curr) < get_pos(*stack, wall))
			{
				printf("curr: %zu\n", curr);
				while (!stack_ascending(*stack, get_pos(*stack, wall)))
					if ((*stack)->content_size > ((*stack)->next)->content_size)
					{
						ins_swap(ins, stack, 0, "sa");
						printf("*sa >  ");print_stack(*stack);printf("\n");
					}
					else
					{
						ins_rotate(ins, stack, 0, "ra");
						printf("*ra >  ");print_stack(*stack);printf("\n");
					}
				curr--;
			}
			else
			{
				ins_rev_rotate(ins, stack, 0, "rra");
				printf("rra <  ");print_stack(*stack);printf("\n");
				if ((*stack)->content_size > ((*stack)->next)->content_size)
				{
					ins_swap(ins, stack, 0, "sa");
					printf("*sa >  ");print_stack(*stack);printf("\n");
				}
			}
	}
}

void		partition(t_list **a, t_list **b, t_list **ins, int part)
{
	int		index;
	int		iter;
	int		wall;

	index = 0;
	iter = 0;
	wall = 0;
	while (*a && (index += part))
	{
		if ((iter = ft_lstsize(*a)) <= part)
		{
			if (iter < 6)
			{
				printf("***bt***\n");
				bt_ascending(a, ins, iter);
			}
			else
			{
				printf("***in***\n");
				in_ascending(a, ins, iter);
			}
			break ;
		}
		wall = get_val_index(*a, index);
		while (*a && iter--)
			if (wall >= *(int*)(*a)->content)
				ins_put(ins, a, b, "pb");
			else
				ins_rotate(ins, a, b, "ra");
	}
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*ins;

	b = 0;
	ins = 0;
	fill_stack(&a, ++av, --ac);
	printf("A:  ");print_stack(a);printf("\n");
	printf("B:  ");print_stack(b);printf("\n    ");
	index_stack(a, ac);
	partition(&a, &b, &ins, 100);
/*	
	for (int i = 0; i < ac; i++)
	{
		printf("%zu ", a->content_size);
		a = a->next;
	}
	printf("\n");
*/
	ft_lstrev(&ins);
	printf("STACK INS:  ");print_stack_ins(ins);printf("\n");
	int h = 0;
	while (ins && ++h)
		ins = ins->next;
	printf("{ins:%d}\nSA:  ", h);print_stack(a);printf("\n");
	printf("SB:  ");print_stack(b);printf("\n");
/*	
	ins = 0;
	bt_ascending(&a, &ins, ac);
	printf("STACK INS:  ");print_stack_ins(ins);printf("\n");
	printf("SA:  ");print_stack(a);printf("\n");
	printf("SB:  ");print_stack(b);printf("\n");
	//quick_sort(&a, &b, ac);
	//printf("\nA: ");print_stack(a);printf("\n");
	//printf("B: ");print_stack(b);printf("\n");
	if (is_sorted_stack(a))
		printf("OK\n");
*/
	return (0);
}
