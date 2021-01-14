/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:16:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/03/31 14:49:42 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_img				*get_new_img(void *mlx, int width, int height)
{
	t_img			*img;
	int				bpp;
	int				size;
	int				endian;

	if (!(img = malloc(sizeof(t_img))))
		return (0);
	img->mlx = mlx;
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &bpp, &size, &endian);
	img->pos.x = 0;
	img->pos.y = 0;
	img->pos.color = 0;
	img->width = width;
	img->height = height;
	return (img);
}

/*
** mask contains to 2 colors [#FFFFFF #FFFFFF]
*/

void				clear_img(t_img *image, size_t mask)
{
	register size_t	iter;
	size_t			resolution;

	resolution = (size_t)image->width * (size_t)image->height;
	iter = resolution >> 1;
	while (iter > 0)
	{
		*((size_t*)image->addr + iter) = mask;
		iter--;
	}
}

void				del_img(t_img *image)
{
	if (image)
	{
		mlx_destroy_image(image->mlx, image->img);
		ft_memdel((void**)&image);
	}
}

int					img_pixel_put(t_img *img, int x, int y, int color)
{
	((int*)img->addr)[img->width * y + x] = color;
	return (color);
}
