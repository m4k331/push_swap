/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/09 20:50:05 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

t_list		*get_ins(t_list **a, t_list **b, int part)
{
	t_list	*ins;
	int		rest;

	ins = 0;
	partition(a, b, &ins, part);
	while ((rest = ft_lstsize(*b)) > part)
		in_mid(a, b, &ins, part);
	if (rest)
		in_descending(a, b, &ins, rest);
	ft_lstrev(&ins);
	return (ins);
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
	printf("B:  ");print_stack(b);printf("\n");
	index_stack(a, ac);
	//for (int i = 0; i < 21; i++)
	//	put_stack(&b, &a);
	//in_mid(&a, &b, &ins, 20);
	//ft_lstrev(&ins);
	ins = get_ins(&a, &b, 16);
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
	return (0);
}
