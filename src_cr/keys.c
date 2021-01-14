/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:15:30 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/06 18:15:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static inline void	next_ins(t_visual *vsr)
{
	if (vsr->ins < vsr->sz_ins)
	{
		vsr->sorted += 2;
		vsr_apply_ins(vsr);
		if (vsr->debug)
			print_debug(vsr->ps, vsr->ins - 1);
	}
	else
		check_vsr_sorted(vsr);
	draw_stacks(vsr);
}

static inline void	prev_ins(t_visual *vsr)
{
	if (vsr->ins > 0)
	{
		vsr->sorted += 2;
		rev_vsr_apply_ins(vsr);
		if (vsr->debug)
			print_debug(vsr->ps, vsr->ins - 1);
	}
	draw_stacks(vsr);
}

int					press_key(int key, void *param)
{
	if (key == 13 || key == 124)
		next_ins((t_visual*)param);
	else if (key == 12 || key == 123)
		prev_ins((t_visual*)param);
	return (1);
}

int					mouse_press(int button, int x, int y, void *param)
{
	if (button == 1 || button == 2)
	{
		if (x <= ((t_visual*)param)->img->width / 2)
			prev_ins((t_visual*)param);
		else
			next_ins((t_visual*)param);
	}
	return (y);
}

int					red_close(void *param)
{
	(void)param;
	clear_visual((t_visual*)param);
	exit(1);
	return (0);
}
