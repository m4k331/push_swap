/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:10:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 22:17:15 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

/*
** The function divides the stack into two parts
*/

static int	partition(int *nums, int size)
{
	int		left;
	int		right;
	int		wall;

	left = 0;
	right = size - 1;
	wall = 0;
	while (left != right)
	{
		if (nums[left] <= nums[wall])
		{
			ft_memswap(&nums[left], &nums[wall], sizeof(int));
			wall = left;
			left++;
		}
		else
		{
			while (nums[right] > nums[wall] && right != left)
				right--;
			ft_memswap(&nums[left], &nums[right], sizeof(int));
		}
	}
	return (wall);
}

/*
** Returns the median on the stack using the qselect algorithm
*/

static int	quickselect(int *nums, int size, int k)
{
	int		part;

	part = partition(nums, size);
	if (part == k - 1)
		return (nums[part]);
	if (part > k - 1)
		size = part + 1;
	else
	{
		k -= part + 1;
		nums += part + 1;
		size -= part + 1;
	}
	return (quickselect(nums, size, k));
}

/*
** Returns the median on the stack using bruteforce
*/

static int	bruteforce(t_list *stack, int k)
{
	t_list	*head;
	t_list	*iter;
	int		count;

	head = stack;
	count = 0;
	while ((iter = head))
	{
		while (iter)
		{
			if (*(int*)iter->content <= *(int*)stack->content)
				count++;
			iter = iter->next;
		}
		if (count == k || !(stack = stack->next))
			break ;
		count = 0;
	}
	return (*(int*)stack->content);
}

/*
** Returns the median
*/

int			get_median(t_list *stack, int size)
{
	int		*nums;
	int		median;
	int		k;

	if (!size)
		return (0);
	nums = (stack ? get_array_nums(stack, size) : 0);
	k = (size % 2 == 1 ? size / 2 + 1 : size / 2);
	if (nums)
	{
		median = quickselect(nums, size, k);
		free(nums);
	}
	else
		median = bruteforce(stack, k);
	return (median);
}
