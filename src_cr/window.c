/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:27:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/31 14:19:29 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_win			*get_new_win(void *mlx, int width, int height, char *name)
{
	t_win		*window;

	if (!(window = malloc(sizeof(t_win))))
		return (0);
	window->mlx = mlx;
	if (!(window->win = mlx_new_window(mlx, width, height, name)))
		free(window);
	else
	{
		window->width = width;
		window->height = height;
		window->name = name;
	}
	return (window);
}

void			del_win(t_win *window)
{
	if (window)
	{
		if (window->mlx && window->win)
			mlx_destroy_window(window->mlx, window->win);
		else if (window->mlx)
			ft_memdel(&window->mlx);
		else if (window->win)
			ft_memdel(&window->win);
		ft_memdel((void**)&window);
	}
}
