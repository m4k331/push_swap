/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:55:44 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 20:58:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#define IS_INT(x) ((x) >= -__INT_MAX__ - 1 && (x) <= __INT_MAX__)

/*
** The function accepts a pointer to the stack and a string value (val)
** that contains an integer in string. If val is valid an integer then
** stack->content = (int)val, otherwise it does not write the content
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

/*
** The function fill stack takes an array strings that contains integers 
** returns 1 if successful, otherwise returns 0
** NOTE: the function is not protected
*/

int			fill_stack2int(t_list *stack, char **vals, int amount)
{
	int		i;

	i = 0;
	while (stack)
	{
		set_int2stack(stack, vals[i]);
		if (!(stack->content))
			break ;
		stack = stack->next;
		i++;
	}
	return ((i == amount ? 1 : 0));
}
