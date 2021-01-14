/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 09:46:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:55:39 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** function that creates an array of int from the stack
*/

static int	*get_array_nums(t_list *stack, int size)
{
	int		*nums;
	int		iter;

	iter = 0;
	if ((nums = (int*)malloc(sizeof(int) * size)))
	{
		while (stack && size--)
		{
			nums[iter++] = *(int*)stack->content;
			stack = stack->next;
		}
	}
	return (nums);
}

/*
** function of sorting integers in an arrays nums
*/

static void	qcksort(int *nums, int left, int right)
{
	int		i;
	int		j;
	int		pivot;

	i = left;
	j = right;
	pivot = nums[left];
	while (i != j)
	{
		if (nums[i] < pivot)
			i++;
		else if (nums[j] > pivot)
			j--;
		else
			ft_memswap(&nums[i], &nums[j], sizeof(int));
	}
	if (i - left > 1)
		qcksort(nums, left, i - 1);
	if (right - j > 1)
		qcksort(nums, j + 1, right);
}

/*
** search and set the min max values in the stack in the range from 0 to size
*/

static void	min_max_instack(t_list *stack, int *min, int *max, int size)
{
	if (stack && size)
	{
		*max = *(int*)stack->content;
		*min = *(int*)stack->content;
		stack->content_size = size;
		while (stack)
		{
			if (*max < *(int*)stack->content && (stack->content_size = size))
				*max = *(int*)stack->content;
			else if (*min > *(int*)stack->content)
				*min = *(int*)stack->content;
			stack = stack->next;
		}
	}
}

/*
** functions index the stack without additional memory (O(n**2) for bad cases)
*/

static void	direct_indexing(t_list *stack, int size)
{
	t_list	*head;
	int		min;
	int		curr;
	int		last;

	min = 0;
	last = 0;
	curr = 0;
	if ((head = stack) && size)
	{
		min_max_instack(stack, &min, &last, size);
		while (--size && (stack = head))
		{
			curr = min;
			while (stack)
			{
				if (curr <= *(int*)stack->content && \
						*(int*)stack->content < last && \
						(stack->content_size = size))
					curr = *(int*)stack->content;
				stack = stack->next;
			}
			last = curr;
		}
	}
}

/*
** function indexes the stack (index is written to content_size)
*/

void		index_stack(t_list *stack, int size)
{
	t_list	*head;
	int		*nums;
	int		index;

	head = stack;
	nums = size ? get_array_nums(stack, size) : 0;
	index = 1;
	if (nums)
	{
		qcksort(nums, 0, size - 1);
		while (index <= size)
		{
			while (nums[index - 1] != *(int*)stack->content)
				stack = stack->next;
			stack->content_size = index;
			stack = head;
			index++;
		}
		ft_memdel((void**)&nums);
	}
	else
		direct_indexing(stack, size);
}
