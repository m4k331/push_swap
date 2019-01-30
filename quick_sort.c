/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:29:38 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/25 21:17:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

static int	get_pivot(t_list *stack, int size)
{
	ssize_t	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (stack && i < size)
	{
		sum += *(int*)stack->content;
		stack = stack->next;
		i++;
	}
	return ((size ? sum / size : 0));
}

static int	pivot_more(t_list *stack, int pivot)
{
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

static void	left_sort(t_list **a, t_list **b, int size)
{
	int		puts;
	int		pivot;

	printf("left_size:%d ", size);
	puts = 0;
	pivot = get_pivot(*a, size);
	printf("pivot:%d\n", pivot);
	if (is_sorted_stack(*a) || !size)
		return ;
	while (size > puts && pivot_more(*a, pivot))
	{
		if (*(int*)(*b)->content > pivot)
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
	if (*b)
	{
		printf("stack a|- ");print_stack(*a);printf("\n");
		printf("stack b|- ");print_stack(*b);printf("\n");
		left_sort(a, b, size - puts);
	}
}

static void	right_sort(t_list **a, t_list **b, int size)
{
	int		puts;
	int		pivot;

	printf("right_size:%d ", size);
	puts = 0;
	pivot = get_pivot(*a, size);
	printf("pivot:%d\n", pivot);
	if (is_sorted_stack(*a) || !size)
		return ;
	while (size > puts && pivot_more(*a, pivot))
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
		right_sort(a, b, size - puts);
	}
	if (*b)
	{
		printf("stack a|- ");print_stack(*a);printf("\n");
		printf("stack b|- ");print_stack(*b);printf("\n");
		left_sort(b, a, get_size_stack(*b));
	}
}

void		quick_sort(t_list **a, t_list **b, int size)
{
	if (*a)
		right_sort(a, b, size);
	if (*b)
		left_sort(a, b, size);
	if (!is_sorted_stack(*a))
		quick_sort(a, b, get_size_stack(*a));
}
