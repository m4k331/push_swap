/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/08 22:35:23 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*ins;

	b = 0;
	ins = 0;
	fill_stack(&a, ++av, --ac);
	printf("A:  ");print_stack(a);printf("\n");
	printf("B:  ");print_stack(b);printf("\n");
	index_stack(a, ac);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
put_stack(&b, &a);
	insertion(&a, &b, &ins, 15);
	ft_lstrev(&ins);
	printf("2STACK INS:  ");print_stack_ins(ins);printf("\n");
	int h = 0;
	while (ins && ++h)
		ins = ins->next;
	printf("{ins:%d}\nSA:  ", h);print_stack(a);printf("\n");
	printf("SB:  ");print_stack(b);printf("\n");
/*
	partition(&a, &b, &ins, 6);
	in_descending(&a, &b, &ins, ft_lstsize(b));
	ft_lstrev(&ins);
	printf("2STACK INS:  ");print_stack_ins(ins);printf("\n");
	int h = 0;
	while (ins && ++h)
		ins = ins->next;
	printf("{ins:%d}\nSA:  ", h);print_stack(a);printf("\n");
	printf("SB:  ");print_stack(b);printf("\n");
*/
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
