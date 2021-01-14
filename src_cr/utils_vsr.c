/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vsr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:37:03 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/07 15:37:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void				clear_visual(t_visual *vsr)
{
	del_win(vsr->win);
	del_img(vsr->img);
	del_img(vsr->panel);
	del_ps(vsr->ps);
	del_vv(vsr->vv, vsr->size);
}

void				check_vsr_sorted(t_visual *vsr)
{
	t_list			*lst;

	lst = vsr->ps->a;
	vsr->sorted = 1;
	if (lst)
		while (lst->next)
		{
			if (*(int*)lst->content > *(int*)(lst->next)->content && \
																vsr->sorted--)
				break ;
			lst = lst->next;
		}
	if (vsr->sorted && ft_lstsize(vsr->ps->b) == 0)
		ft_putstr(KGRN"OK\n"KNRM);
	else
		ft_putstr(KRED"KO\n"KNRM);
	refresh_panel(vsr);
}

void				init_visual(t_visual *vsr, t_ps *ps, t_vector **vv, \
																	size_t size)
{
	t_list			*lst;
	int				max;

	lst = ps->a;
	max = (lst ? ABS(*(int*)ps->a->content) : 0);
	while (lst)
	{
		if (max < ABS(*(int*)lst->content))
			max = ABS(*(int*)lst->content);
		lst = lst->next;
	}
	vsr->mlx = mlx_init();
	vsr->win = get_new_win(vsr->mlx, W, H, "push_swap");
	vsr->img = get_new_img(vsr->mlx, W - INDENT, H);
	vsr->panel = get_new_img(vsr->mlx, INDENT, H);
	vsr->ps = ps;
	vsr->vv = vv;
	vsr->size = size;
	vsr->width_sq = (W - INDENT) / size;
	vsr->max_height_sq = H * 0.45;
	vsr->max_abs_value = max;
	vsr->mid_line = H / 2;
	vsr->ins = 0;
	vsr->sz_ins = ft_lstsize(vsr->ps->ins);
}
