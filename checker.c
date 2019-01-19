/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:39:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 20:59:31 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

int			main(int ac, char **av)
{
/*
 	t_list	*a;

	fill_stack(a, av, ac);
	if (a)
		ft_printf("filled!\n");
	else
		ft_printf("error\n");
*/
	t_list	*a;

	a = create_stack(ac - 1);
	if (fill_stack2int(a, ++av, --ac))
		while (a)
		{
			printf("a->%d\n", *(int*)(a->content));
			a = a->next;
		}
	else
		printf("error\n");
	return (0);
}
