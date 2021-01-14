/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:16:04 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/11 14:16:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static inline void		apply_ins_swap(t_ps *ps, char *in)
{
	if (in[1] == 'a' || in[1] == 's')
		swap_stack(&ps->a);
	if (in[1] == 'b' || in[1] == 's')
		swap_stack(&ps->b);
}

static inline void		apply_ins_rotate(t_ps *ps, char *in)
{
	if (in[1] == 'a' || in[1] == 'r')
		rotate_stack(&ps->a);
	if (in[1] == 'b' || in[1] == 'r')
		rotate_stack(&ps->b);
}

static inline void		apply_ins_put(t_ps *ps, char *in)
{
	if (in[1] == 'a')
		put_stack(&ps->a, &ps->b);
	else if (in[1] == 'b')
		put_stack(&ps->b, &ps->a);
}

static inline void		apply_ins_rev_rotate(t_ps *ps, char *in)
{
	if (in[2] == 'a' || in[2] == 'r')
		rev_rotate_stack(&ps->a);
	if (in[2] == 'b' || in[2] == 'r')
		rev_rotate_stack(&ps->b);
}

void					apply_ins_cr(t_ps *ps, char *in)
{
	if (in[2] == 0)
	{
		if (*in == 's')
			apply_ins_swap(ps, in);
		else if (*in == 'p')
			apply_ins_put(ps, in);
		else
			apply_ins_rotate(ps, in);
	}
	else
		apply_ins_rev_rotate(ps, in);
}
