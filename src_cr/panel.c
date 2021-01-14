/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:58:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/07 16:58:05 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static inline void	draw_map(t_visual *vsr, int left, int mid)
{
	t_px			bgn;
	t_px			end;

	set_px(&bgn, left, mid + 35, CUR);
	set_px(&end, left + 50, mid + 85, CUR_DWN);
	draw_square(vsr->panel, bgn, end, 0);
	set_px(&bgn, left, mid + 110, PRE);
	set_px(&end, left + 50, mid + 160, PRE_DWN);
	draw_square(vsr->panel, bgn, end, 0);
	set_px(&bgn, left, mid + 185, DEF_POS);
	set_px(&end, left + 50, mid + 235, POS_DWN);
	draw_square(vsr->panel, bgn, end, 0);
	set_px(&bgn, left, mid + 260, DEF_NEG);
	set_px(&end, left + 50, mid + 310, NEG_DWN);
	draw_square(vsr->panel, bgn, end, 0);
}

static inline void	draw_status(t_visual *vsr, int left, int bot)
{
	mlx_string_put(vsr->mlx, vsr->win->win, left, bot, ORANGE, "STATUS:");
	if (vsr->sorted == 1)
		mlx_string_put(vsr->mlx, vsr->win->win, left + 75, bot, VIM, "OK");
	else if (vsr->sorted == 0)
		mlx_string_put(vsr->mlx, vsr->win->win, left + 75, bot, VIM, "KO");
	else
		mlx_string_put(vsr->mlx, vsr->win->win, left + 75, bot, VIM, "Sorting");
}

void				refresh_panel(t_visual *vsr)
{
	char			*in;
	int				l;
	int				m;

	in = (vsr->ins > 0 ? ft_lstat(vsr->ps->ins, vsr->ins - 1)->content : "");
	l = INDENT / 10;
	m = H / 3;
	clear_img(vsr->panel, PANEL_BG);
	draw_map(vsr, l, m);
	mlx_put_image_to_window(vsr->mlx, vsr->win->win, vsr->panel->img, 0, 0);
	mlx_string_put(vsr->mlx, vsr->win->win, l, l, ORANGE, "INSTRUCTIONS:");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 185, l, ORANGE, \
	ft_itoa(vsr->ins));
	mlx_string_put(vsr->mlx, vsr->win->win, l, m / 2, ORANGE, "KEYS:");
	mlx_string_put(vsr->mlx, vsr->win->win, l, m / 2 + 30, VIM, \
	"W - go to the next ins");
	mlx_string_put(vsr->mlx, vsr->win->win, l, m / 2 + 55, VIM, \
	"Q - return to previous");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 55, m + 50, VIM, "selected");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 55, m + 125, VIM, "previous");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 55, m + 200, VIM, "positive");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 55, m + 270, VIM, "negative");
	mlx_string_put(vsr->mlx, vsr->win->win, l + 135, l, VIM, in);
	mlx_string_put(vsr->mlx, vsr->win->win, l, m, ORANGE, "COLORS:");
	draw_status(vsr, l, (m + m) * 1.2);
}
