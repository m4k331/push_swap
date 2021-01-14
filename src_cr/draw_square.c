/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:58:02 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/31 17:50:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static inline void	normalize_coords(t_px *bgn, t_px *end)
{
	int				delta;

	delta = bgn->y - end->y;
	if (bgn->x > end->x)
		swap_coords(&bgn, &end);
	if (bgn->y > end->y)
	{
		bgn->y -= delta;
		end->y += delta;
	}
}

int					draw_square(t_img *img, t_px bgn, t_px end, char horizontal)
{
	int				edge;

	normalize_coords(&bgn, &end);
	if (horizontal)
	{
		edge = end.y;
		while (bgn.y <= edge)
		{
			end.y = bgn.y;
			draw_line(img, bgn, end);
			bgn.y++;
		}
	}
	else
	{
		edge = end.x;
		while (bgn.x <= edge)
		{
			end.x = bgn.x;
			draw_line(img, bgn, end);
			bgn.x++;
		}
	}
	return (0);
}
