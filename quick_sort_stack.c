/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:47:50 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/25 19:51:12 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

static int	get_pivot(t_list *stack)
{
	ssize_t	sum;
	int		count;

	sum = 0;
	count = 0;
	while (stack)
	{
		sum += *(int*)stack->content;
		count++;
		stack = stack->next;
	}
	return (sum / count);
}

static int	pivot_more(t_list *stack, int pivot)

	int		more;

	more = 0;
	while (stack)
	{
		if (*(int*)stack->content < pivot)
		{
			more = 1;
			break ;
		}
		stack = stack->next;
	}
	return (more);
}

static int	pivot_less(t_list *stack, int pivot)
{
	int		less;

	less = 0;
	while (stack)
	{
		if (*(int*)stack->content > pivot)
		{
			less = 1;
			break ;
		}
		stack = stack->next;
	}
	return (less);
}
/*
static void	rev_sort_me(t_list **a, t_list **b, int pivot, int len)
{
	int		puts;

	printf("rev_len%d:", len);
	puts = 0;
	if (is_sorted_stack(*a) || *a == NULL || !run(*a, pivot))
		return ;
	while (len > puts && rev_run(*a, pivot))
	{
		if (*(int*)(*a)->content > pivot)
		{
			put_stack(b, a);
			printf("put:>>>\n");print_stack(*a);printf("\n");
			print_stack(*b);printf("\n\n");
			puts++;
		}
		else
		{
			rotate_stack(a);
			printf("rot:>>>\n");print_stack(*a);printf("\n");
			print_stack(*b);printf("\n\n");
		}
	}
	if (*a)
	{
		printf("stack a|- ");print_stack(*a);printf("\n");
		printf("stack b|- ");print_stack(*b);printf("\n");
		rev_sort_me(a, b, get_pivot(*a), len - puts);
	}
	if (len)
		sort_me(a, b, get_pivot(*a), len);
}
*/
void		quick_sort(t_list **a, t_list **b, int size)
{
	int		puts;
	int		pivot;

	printf("size%d:", size);
	puts = 0;
	pivot = get_pivot(*a);
	if (is_sorted_stack(*a))
		return ;
	while (size > puts && pivot_less(*a, pivot))
	{
		if (*(int*)(*a)->content < pivot)
		{
			put_stack(b, a);
			printf("put:>>>\n");print_stack(*a);printf("\n");
			print_stack(*b);printf("\n\n");
			puts++;
		}
		else
		{
			rotate_stack(a);
			printf("rot:>>>\n");print_stack(*a);printf("\n");
			print_stack(*b);printf("\n\n");
		}
	}
	if (*a)
	{
		printf("*a\n");
		printf("stack a|- ");print_stack(*a);printf("\n");
		printf("stack b|- ");print_stack(*b);printf("\n");
		quick_sort(a, b, len - puts);
	}
	if (*b)
	{
		printf("*b\n");
		printf("stack a|- ");print_stack(*a);printf("\n");
		printf("stack b|- ");print_stack(*b);printf("\n");
		//rev_(a, b, get_pivot(*b), len);
	}
}
