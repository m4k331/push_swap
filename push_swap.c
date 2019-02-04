/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 17:56:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack.h"

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*ins;

	b = 0;
	fill_stack(&a, ++av, --ac);
	printf("A:  ");print_stack(a);printf("\n");
	printf("B:  ");print_stack(b);printf("\n");
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
	return (0);
}
