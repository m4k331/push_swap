/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:23:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/25 19:42:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;

	if (!(b = 0) && fill_stack(&a, ++av, --ac))
	{
		c = a;
		d = b;
		quick_sort(&a, &b, ac);
		
	//	printf("stack c->a|- ");print_stack(c);printf("\n");
	//	printf("stack d->b|- ");print_stack(d);printf("\n");
		printf("\nANSWER:\nstack a|- ");print_stack(a);printf("\n");
		printf("stack b|- ");print_stack(b);printf("\n");
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
