/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 23:27:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack.h"

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = 0;
	fill_stack(&a, ++av, --ac);
	printf("[%d] INPUT:  ", ac);print_stack(a);printf("\n");

	int		*nums = get_array_nums(a, ac);
	intqsort(nums, 0, ac - 1);
	set_position2val(a, nums);
	//quick_sort(&a, &b, ac);
	//printf("\nA: ");print_stack(a);printf("\n");
	//printf("B: ");print_stack(b);printf("\n");
	if (is_sorted_stack(a))
		printf("OK\n");
	return (0);
}
