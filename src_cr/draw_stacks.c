/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:25:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/06 16:25:46 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static inline void	set_color(t_vector *v, t_px *bgn, t_px *end, int top)
{
	int				vec_color;

	vec_color = *(int*)ft_vat(v, v->iter - 1);
	if (vec_color == CUR)
	{
		bgn->color = (top == -1 ? vec_color : CUR_DWN);
		end->color = (top == -1 ? CUR_DWN : vec_color);
	}
	else if (vec_color == DEF_NEG)
	{
		bgn->color = (top == -1 ? vec_color : NEG_DWN);
		end->color = (top == -1 ? NEG_DWN : vec_color);
	}
	else if (vec_color == DEF_POS)
	{
		bgn->color = (top == -1 ? vec_color : POS_DWN);
		end->color = (top == -1 ? POS_DWN : vec_color);
	}
	else
	{
		bgn->color = (top == -1 ? vec_color : PRE_DWN);
		end->color = (top == -1 ? PRE_DWN : vec_color);
	}
}

static inline void	draw_stack(t_visual *vsr, t_list *lst, int top)
{
	t_px			bgn;
	t_px			end;
	int				next;

	next = 0;
	end.y = vsr->mid_line;
	while (lst)
	{
		bgn.x = next;
		bgn.y = vsr->mid_line + top * ((ABS(*(int*)lst->content) / \
						(float)vsr->max_abs_value) * (float)vsr->max_height_sq);
		end.x = next + vsr->width_sq;
		set_color(vsr->vv[lst->content_size], &bgn, &end, top);
		draw_square(vsr->img, bgn, end, 0);
		lst = lst->next;
		next += vsr->width_sq;
	}
}

void				draw_stacks(t_visual *vsr)
{
	t_px			bgn;
	t_px			end;

	clear_img(vsr->img, STACK_BG);
	set_px(&bgn, 0, vsr->mid_line, 0);
	set_px(&end, vsr->img->width, vsr->mid_line, 0);
	draw_stack(vsr, vsr->ps->a, -1);
	draw_stack(vsr, vsr->ps->b, 1);
	draw_line(vsr->img, bgn, end);
	set_px(&bgn, 0, 0, 0);
	set_px(&end, 0, vsr->img->height, 0);
	draw_line(vsr->img, bgn, end);
	refresh_panel(vsr);
	mlx_put_image_to_window(vsr->mlx, vsr->win->win, vsr->img->img, INDENT, 0);
}
