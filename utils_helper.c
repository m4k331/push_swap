/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:56:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 21:10:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int			*get_array_nums(t_list *stack, int size)
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
