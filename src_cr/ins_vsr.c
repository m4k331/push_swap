/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_vsr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:01:07 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/06 22:01:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void inline	refresh_color(t_ps *ps, t_vector **vv, int rev)
{
	if (rev == 0)
	{
		refresh_color_vv(ps->a, vv);
		refresh_color_vv(ps->b, vv);
	}
	else
	{
		clear_pre_color_vv(ps->a, vv);
		clear_pre_color_vv(ps->b, vv);
	}
}

int					ins_vsr_swap(t_ps *ps, t_vector **vv, char *in, int rev)
{
	int				color;

	color = CUR;
	refresh_color(ps, vv, rev);
	if ((in[1] == 'a' || in[1] == 's') && ps && ps->a)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->a->content_size], &color, sizeof(int));
		swap_stack(&ps->a);
	}
	if ((in[1] == 'b' || in[1] == 's') && ps && ps->b)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->b->content_size], &color, sizeof(int));
		swap_stack(&ps->b);
	}
	return (1);
}

int					ins_vsr_put(t_ps *ps, t_vector **vv, char *in, int rev)
{
	int				color;

	color = CUR;
	refresh_color(ps, vv, rev);
	if ((in[1] == 'a') && ps && ps->b)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->b->content_size], &color, sizeof(int));
		put_stack(&ps->a, &ps->b);
	}
	else if ((in[1] == 'b') && ps && ps->a)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->a->content_size], &color, sizeof(int));
		put_stack(&ps->b, &ps->a);
	}
	return (1);
}

int					ins_vsr_rot(t_ps *ps, t_vector **vv, char *in, int rev)
{
	int				color;

	color = CUR;
	refresh_color(ps, vv, rev);
	if ((in[1] == 'a' || in[1] == 'r') && ps && ps->a)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->a->content_size], &color, sizeof(int));
		rotate_stack(&ps->a);
	}
	if ((in[1] == 'b' || in[1] == 'r') && ps && ps->b)
	{
		if (rev == 0)
			ft_vpush_back(vv[ps->b->content_size], &color, sizeof(int));
		rotate_stack(&ps->b);
	}
	return (1);
}

int					ins_vsr_rev_rot(t_ps *ps, t_vector **vv, char *in, int rev)
{
	int				last;
	int				color;

	color = CUR;
	refresh_color(ps, vv, rev);
	if ((in[2] == 'a' || in[2] == 'r') && ps && ps->a)
	{
		last = (int)ft_lstlast(ps->a)->content_size;
		if (rev == 0)
			ft_vpush_back(vv[last], &color, sizeof(int));
		rev_rotate_stack(&ps->a);
	}
	if ((in[2] == 'b' || in[2] == 'r') && ps && ps->b)
	{
		last = (int)ft_lstlast(ps->b)->content_size;
		if (rev == 0)
			ft_vpush_back(vv[last], &color, sizeof(int));
		rev_rotate_stack(&ps->b);
	}
	return (1);
}
