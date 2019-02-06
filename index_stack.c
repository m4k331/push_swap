/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 09:46:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/06 12:09:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

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

static void	min_max_instack(t_list *stack, int *min, int *max, int size)
{
	t_list	*head;

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

void		index_stack(t_list *stack, int size)
{
	t_list	*head;
	int		*nums;
	int		index;

	head = stack;
	nums = get_array_nums(stack, size);
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
	}
	else
		direct_indexing(stack, size);
}
