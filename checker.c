/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:39:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 17:08:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
#define IS_INT(x) ((x) >= -__INT_MAX__ - 1 && (x) <= __INT_MAX__)

/*
void		fill_stack(t_list *a, char **av, int ac)
{
	t_list	*head;

	head = a;
	while (ac-- > 1)
	{
		if (k)
	}
}
*/
void		set_int2stack(t_list *stack, char *val)
{
	long	res;
	int		*p_res;
	int		sign;

	res = 0;
	p_res = 0;
	while (ft_isspace(*val))
		val++;
	sign = *val == '-' ? -1 : 1;
	if (*val == '-' || *val == '+')
		val++;
	while (*val == 48)
		val++;
	while (ft_isdigit(*val) && res < __INT_MAX__)
		res = res * 10 + (*val++ - 48);
	while (ft_isspace(*val))
		val++;
	res *= sign;
	if (!*val && IS_INT(res) && (p_res = (int*)malloc(sizeof(int))))
	{
		*p_res = (int)(res);
		stack->content = (void*)p_res;
		stack->content_size = sizeof(int);
	}
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

	a = ft_lstnew(0, 0);
	set_int2stack(a, av[1]);
	if (a->content)
		printf("a->content:%d\na->content_size:%zu\n", *(int*)(a->content), a->content_size);
	else
		printf("arg invalid\n");
	return (0);
}
