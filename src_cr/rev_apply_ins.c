/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:47:44 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/07 15:47:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void				vsr_apply_ins(t_visual *vsr)
{
	char			*in;
	int				code;

	code = ft_lstat(vsr->ps->ins, vsr->ins)->content_size;
	in = (char*)ft_lstat(vsr->ps->ins, vsr->ins)->content;
	if (code == 0)
		ins_vsr_swap(vsr->ps, vsr->vv, in, 0);
	else if (code == 1)
		ins_vsr_put(vsr->ps, vsr->vv, in, 0);
	else if (code == 2)
		ins_vsr_rot(vsr->ps, vsr->vv, in, 0);
	else
		ins_vsr_rev_rot(vsr->ps, vsr->vv, in, 0);
	vsr->ins++;
}

static inline void	rev_apply_code1(t_visual *vsr, char *in)
{
	if (in[1] == 'a')
		ins_vsr_put(vsr->ps, vsr->vv, "pb", 1);
	else
		ins_vsr_put(vsr->ps, vsr->vv, "pa", 1);
}

static inline void	rev_apply_code2(t_visual *vsr, char *in)
{
	if (in[1] == 'a')
		ins_vsr_rev_rot(vsr->ps, vsr->vv, "rra", 1);
	else if (in[1] == 'b')
		ins_vsr_rev_rot(vsr->ps, vsr->vv, "rrb", 1);
	else
		ins_vsr_rev_rot(vsr->ps, vsr->vv, "rrr", 1);
}

static inline void	rev_apply_code3(t_visual *vsr, char *in)
{
	if (in[2] == 'a')
		ins_vsr_rot(vsr->ps, vsr->vv, "ra", 1);
	else if (in[2] == 'b')
		ins_vsr_rot(vsr->ps, vsr->vv, "rb", 1);
	else if (in[2] == 'r')
		ins_vsr_rot(vsr->ps, vsr->vv, "rrr", 1);
}

void				rev_vsr_apply_ins(t_visual *vsr)
{
	char			*in;
	int				code;

	vsr->ins--;
	code = ft_lstat(vsr->ps->ins, vsr->ins)->content_size;
	in = (char*)ft_lstat(vsr->ps->ins, vsr->ins)->content;
	if (code == 0)
		ins_vsr_swap(vsr->ps, vsr->vv, in, 1);
	else if (code == 1)
		rev_apply_code1(vsr, in);
	else if (code == 2)
		rev_apply_code2(vsr, in);
	else
		rev_apply_code3(vsr, in);
}
