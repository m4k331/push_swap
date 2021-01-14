/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_color_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:47:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/03 22:47:26 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void				run_visualization(t_ps *ps, t_vector **vv, size_t size, \
																	char flag)
{
	t_visual		vsr;

	vsr.debug = (flag & 4);
	vsr.sorted = 2;
	init_visual(&vsr, ps, vv, size);
	draw_stacks(&vsr);
	mlx_hook(vsr.win->win, 17, 0, red_close, &vsr);
	mlx_hook(vsr.win->win, 2, 0, press_key, &vsr);
	mlx_mouse_hook(vsr.win->win, mouse_press, &vsr);
	mlx_loop(vsr.mlx);
}

int					run_debug(t_ps *ps)
{
	char			*in;
	int				iter;
	int				size;

	iter = -1;
	in = 0;
	size = ft_lstsize(ps->ins);
	print_debug(ps, iter);
	while (++iter < size && get_next_ins())
	{
		in = (char*)ft_lstat(ps->ins, iter)->content;
		apply_ins_cr(ps, in);
		print_debug(ps, iter);
	}
	check_sorted(ps);
	return (1);
}

int					run_checking(t_ps *ps)
{
	int				iter;
	int				size;

	iter = -1;
	size = ft_lstsize(ps->ins);
	while (++iter < size)
		apply_ins_cr(ps, (char*)ft_lstat(ps->ins, iter)->content);
	check_sorted(ps);
	return (1);
}
