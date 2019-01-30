/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:55:44 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 19:48:14 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#define IS_INT(x) ((x) >= -__INT_MAX__ - 1 && (x) <= __INT_MAX__)

/*
** The function accepts a pointer to the stack and a string value (val)
** that contains an integer in string. If val is valid an integer then
** stack->content = val, otherwise it does not write the content
*/

void		set_val2stack(t_list *stack, char *val)
{
	t_val	*val_res;
	long	res;
	int		sign;

	res = 0;
	val_res = 0;
	sign = *val == '-' ? -1 : 1;
	if (*val == '-' || *val == '+')
		val++;
	while (*val == 48)
		val++;
	while (ft_isdigit(*val) && res < __INT_MAX__)
		res = res * 10 + (*val++ - 48);
	res *= sign;
	if (!*val && IS_INT(res) && (val_res = (t_val*)malloc(sizeof(t_val))))
	{
		val_res->num = (int)res;
		stack->content = (void*)val_res;
		stack->content_size = sizeof(t_val);
	}
}

/*
** The function fill stack takes an array strings that contains val (integers)
** returns 1 if successful, otherwise returns 0
** NOTE: the function is not protected
*/

int			fill_stack2val(t_list *stack, char **vals, int amount)
{
	int		i;

	i = 0;
	while (stack)
	{
		set_val2stack(stack, vals[i]);
		if (!(stack->content))
			break ;
		stack = stack->next;
		i++;
	}
	return ((i == amount ? 1 : 0));
}

/*
** The function of checking duplicate content in the stack
** returns 1 if found duplicate, otherwise returns 0
*/

int			check_dup(t_list *stack)
{
	t_list	*head;
	int		dup;

	dup = 0;
	head = stack;
	while (head && !dup)
	{
		while (stack->next)
		{
			stack = stack->next;
			if (((t_val*)head->content)->num == ((t_val*)stack->content)->num)
			{
				dup = 1;
				break ;
			}
		}
		head = head->next;
		stack = head;
	}
	return (dup);
}

/*
** The function filled stack with an integers
** In case of invalid input, the function clears the stack and return NULL
*/

int			fill_stack(t_list **stack, char **vals, int size)
{
	int		err;

	err = 0;
	*stack = create_stack(size);
	if ((fill_stack2val(*stack, vals, size)))
		err = check_dup(*stack);
	else
		err = 1;
	if (err)
		ft_lstdel(stack, del_content);
	return (!err);
}
