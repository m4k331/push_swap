/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_p1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:53:53 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/27 22:56:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		c6(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_right(img, bgn, end);
	if (end->y > img->height - 2)
		clip_end_bottom(img, bgn, end);
	return (1);
}

int		c8(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_top(img, bgn, end);
	return (1);
}

int		ca(t_img *img, t_px *bgn, t_px *end)
{
	clip_end_right(img, bgn, end);
	if (end->y < 1)
		clip_end_top(img, bgn, end);
	return (1);
}
