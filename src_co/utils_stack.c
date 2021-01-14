/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:57:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 17:51:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Check stack a is asceding sorted returns 1 if sorted else 0
*/

int			is_sorted_stack(t_list *stack)
{
	int		sorted;
	t_list	*prev;

	sorted = 1;
	prev = 0;
	if (stack && stack->next)
		while (stack->next)
		{
			prev = stack;
			stack = stack->next;
			if (*(int*)prev->content > *(int*)stack->content)
			{
				sorted = 0;
				break ;
			}
		}
	return (sorted);
}

/*
** The function for deleting content in the stack
*/

void		del_content(void *content, size_t size)
{
	if (content)
		ft_memdel((void**)&content);
	size = 0;
}

/*
** The function displays the contents of the stack in stdin
*/

void		print_stack(t_list *stack)
{
	while (stack)
	{
		ft_putnbr(*(int*)stack->content);
		write(1, " ", 1);
		stack = stack->next;
	}
}

void		print_stack_ins(t_list *stack, int fd)
{
	while (stack)
	{
		ft_putstr_fd(stack->content, fd);
		write(fd, "\n", 1);
		stack = stack->next;
	}
}
