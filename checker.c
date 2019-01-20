/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:39:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/20 15:29:02 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

/*
** The function of executing instructions for stacks
** returns 1 if executed successfully, or 0 if not
*/

int			exec_inst(t_list *a, t_list *b, char *inst)
{

}

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

	if (ac > 1)
	{
		fill_stack(&a, ++av, --ac);
		if (a)
			while (a)
			{
				printf("a->%d\n", *(int*)(a->content));
				a = a->next;
			}
		else
			printf("error\n");
	}
	return (0);
}
