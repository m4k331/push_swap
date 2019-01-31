/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:29:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/31 20:55:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			ins_swap(t_list **ins, t_list **a, t_list **b, char* in)
{
	t_list	*new;
	char	*str;

	str = 0;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if ((str = (char*)malloc(3)))
		{
			if (in[1] == 'a' || in[1] == 's')
				swap_stack(a);
			if (in[1] == 'b' || in[1] == 's')
				swap_stack(b);
			memcpy(str, in, 3);
			new->content = (void*)str;			
			new->next = *ins;
			*ins = new;
		}
		else
			ft_memdel((void**)&new);
	}
	return ((str ? 1 : 0));
}

int			ins_put(t_list **ins, t_list **a, t_list **b, char* in)
{
	t_list	*new;
	char	*str;

	str = 0;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if ((str = (char*)malloc(3)))
		{
			if (in[1] == 'a')
				put_stack(a, b);
			if (in[1] == 'b')
				put_stack(b, a);
			memcpy(str, in, 3);
			new->content = (void*)str;			
			new->next = *ins;
			*ins = new;
		}
		else
			ft_memdel((void**)&new);
	}
	return ((str ? 1 : 0));
}

int			ins_rotate(t_list **ins, t_list **a, t_list **b, char* in)
{
	t_list	*new;
	char	*str;

	str = 0;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if ((str = (char*)malloc(3)))
		{
			if (in[1] == 'a' || in[1] == 'r')
				rotate_stack(a);
			if (in[1] == 'b' || in[1] == 'r')
				rotate_stack(b);
			memcpy(str, in, 3);
			new->content = (void*)str;			
			new->next = *ins;
			*ins = new;
		}
		else
			ft_memdel((void**)&new);
	}
	return ((str ? 1 : 0));
}

int			ins_rev_rotate(t_list **ins, t_list **a, t_list **b, char* in)
{
	t_list	*new;
	char	*str;

	str = 0;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if ((str = (char*)malloc(4)))
		{
			if (in[2] == 'a' || in[2] == 'r')
				rev_rotate_stack(a);
			if (in[2] == 'b' || in[2] == 'r')
				rev_rotate_stack(b);
			memcpy(str, in, 4);
			new->content = (void*)str;			
			new->next = *ins;
			*ins = new;
		}
		else
			ft_memdel((void**)&new);
	}
	return ((str ? 1 : 0));
}
