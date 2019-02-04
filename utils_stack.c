/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:57:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/04 09:50:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

/*
** Creating new empty stack (single linked list)
*/

t_list		*create_stack(int size)
{
	int		count;
	t_list	*head;
	t_list	*iter;

	count = 0;
	if (!(count++ < size && (head = ft_lstnew(0, 0))))
		return (0);
	iter = head;
	while (count < size)
		if ((iter->next = ft_lstnew(0, 0)) && ++count)
			iter = iter->next;
		else
			break ;
	if (count != size)
		while (head)
		{
			iter = head->next;
			free(head);
			head = iter;
		}
	return (head);
}

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
** Function clearing two stacks
*/

void		clear2stacks(t_list *a, t_list *b)
{
	if (a)
		ft_lstdel(&a, del_content);
	if (b)
		ft_lstdel(&b, del_content);
	a = 0;
	b = 0;
}

/*
** The function displays the contents of the stack in stdin
*/

void		print_stack(t_list *stack)
{
	while (stack)
	{
		if (stack->content)
			printf("%d ", *(int*)stack->content);
		stack = stack->next;
	}
}

void		print_stack_ins(t_list *stack)
{
	while (stack)
	{
		if (stack->content)
			printf("%s ", (char*)stack->content);
		stack = stack->next;
	}
}
