/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:10:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/10 10:37:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** Returns the median
*/

int			get_median(t_list *stack, int size)
{
	ssize_t	median;
	int		divide;

	median = 0;
	divide = 0;
	if (size)
	{
		while (stack && size--)
		{
			median += stack->content_size;
			stack = stack->next;
			divide++;
		}
		median /= divide;
	}
	return (median);
}
