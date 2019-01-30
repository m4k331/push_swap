/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:38:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 23:27:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void		intqsort(int *src, int start, int end)
{
	size_t	left;
	size_t	right;

	right = end;
	left = start;
	while (left < right)
		if (src[left] < src[start])
			left++;
		else if (src[right--] <= src[start])
			ft_memswap(&src[left], &src[right + 1], sizeof(int));
	if (left - start > 1)
		intqsort(src, start, left - 1);
	if (end - right > 1)
		intqsort(src, right + 1, end);
}

void		set_position2val(t_list *stack, int *nums)
{
	int		index;

	index = 0;
	while (stack)
	{
		while (((t_val*)stack->content)->num != nums[index])
			index++;
		((t_val*)stack->content)->pos = index + 1;
		stack = stack->next;
		index = 0;
	}
}
