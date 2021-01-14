/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:55:44 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 17:51:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#define IS_INT(x) ((x) >= -__INT_MAX__ - 1 && (x) <= __INT_MAX__)

/*
** The function accepts a pointer to the stack and a string value (val)
** that contains an integer in string. If val is valid an integer then
** stack->content = (int)val, otherwise it does not write the content
*/

static void			set_int2stack(t_list *stack, char *val)
{
	long			res;
	int				*p_res;
	int				sign;

	res = 0;
	p_res = 0;
	sign = *val == '-' ? -1 : 1;
	if (*val == '-' || *val == '+')
		val++;
	while (*val == 48)
		val++;
	while (ft_isdigit(*val) && res < __INT_MAX__)
		res = res * 10 + (*val++ - 48);
	res *= sign;
	if (!*val && IS_INT(res) && (p_res = (int*)malloc(sizeof(int))))
	{
		*p_res = (int)(res);
		stack->content = (void*)p_res;
		stack->content_size = sizeof(int);
	}
}

/*
** The function of checking duplicate content in the stack
** returns 1 if found duplicate, otherwise returns 0
*/

static int			check_dup(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int*)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
** Freeing space in array vals
*/

static inline void	free_vals(char ***vals)
{
	char			**iter;

	iter = *vals;
	if (iter)
	{
		while (*iter)
		{
			free(*iter);
			iter++;
		}
		free(*vals);
		*vals = 0;
	}
}

/*
** The function fill stack takes an array strings that contains integers
** returns 1 if successful, otherwise returns 0
** NOTE: the function is not protected
*/

static int			fill_stack2int(t_list **stack, char **args, int amount)
{
	t_list			*lst;
	char			**vals;
	int				i;

	lst = 0;
	vals = 0;
	while ((i = -1) && amount--)
	{
		vals = ft_strsplit(*args++, ' ');
		while (vals[++i])
			if ((lst = ft_lstnew(0, 0)))
			{
				set_int2stack(lst, vals[i]);
				if (!lst->content || check_dup(*stack, *(int*)lst->content))
				{
					free_vals(&vals);
					return (0);
				}
				ft_lstaddlast(stack, lst);
			}
			else
				return (0);
		free_vals(&vals);
	}
	return (1);
}

/*
** The function filled stack with an integers
** In case of invalid input, the function clears the stack and return -1
*/

int					fill_stack(t_list **stack, char **vals, int size)
{
	if (!fill_stack2int(stack, vals, size))
	{
		ft_lstdel(stack, del_content);
		return (-1);
	}
	return (0);
}
