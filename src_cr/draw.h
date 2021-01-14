/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:54:20 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 16:56:49 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include "color.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define W			1920
# define H 			1200
# define INDENT		250
# define ABS(x)		((x) < 0 ? -1 * (x) : (x))
# define FPX(x)		(float)((float)1.0 - ((float)(x) - (int)(x)))
# define SPX(x)		(float)((float)(x) - (int)(x))
# define NEGATIVE(x, y) ((x) < 0 || (y) < 0)
# define OVER(x, y, x_over, y_over) ((x) > (x_over) || (y) > (y_over))

/*
** ################################## PX ######################################
*/

typedef struct	s_px
{
	int			x;
	int			y;
	int			color;
}				t_px;

void			set_px(t_px *px, int x, int y, int color);

/*
** ################################ IMG #######################################
*/

typedef struct	s_img
{
	void		*mlx;
	void		*img;
	void		*addr;
	t_px		pos;
	int			width;
	int			height;
}				t_img;

void			clear_img(t_img *image, size_t mask);
void			del_img(t_img *image);
t_img			*get_new_img(void *mlx, int width, int height);
int				img_pixel_put(t_img *img, int x, int y, int color);

/*
** ################################ WIN #######################################
*/

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	char		*name;
	int			width;
	int			height;
}				t_win;

void			del_win(t_win *window);
t_win			*get_new_win(void *mlx, int width, int height, char *name);

/*
** ################################ UTILS #####################################
*/

void			swap_coords(t_px **bgn, t_px **end);
void			draw_straight_line(t_img *img, t_px *bgn, t_px *end);
void			draw_slant_line(t_img *img, t_px *bgn, t_px *end);
int				get_code_px(t_img *img, t_px *px);

/*
** ############################### COLOR ######################################
*/

int				get_color_v(t_px *bgn, t_px *end, int pos, float transparency);
int				get_color_h(t_px *bgn, t_px *end, int pos, float transparency);
int				set_transparency(int color, float transparency);

/*
** ############################### MAIN #######################################
*/

int				draw_line(t_img *img, t_px bgn, t_px end);
int				draw_square(t_img *img, t_px bgn, t_px end, char horizontal);

/*
** ################################## Clipping ################################
*/

int				fc_line(t_img *img, t_px *bgn, t_px *end);

void			clip_bgn_top(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_bottom(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_right(t_img *img, t_px *bgn, t_px *end);
void			clip_bgn_left(t_img *img, t_px *bgn, t_px *end);

void			clip_end_top(t_img *img, t_px *bgn, t_px *end);
void			clip_end_bottom(t_img *img, t_px *bgn, t_px *end);
void			clip_end_right(t_img *img, t_px *bgn, t_px *end);
void			clip_end_left(t_img *img, t_px *bgn, t_px *end);

int				c0(t_img *img, t_px *bgn, t_px *end);
int				c2(t_img *img, t_px *bgn, t_px *end);
int				c4(t_img *img, t_px *bgn, t_px *end);
int				c6(t_img *img, t_px *bgn, t_px *end);
int				c8(t_img *img, t_px *bgn, t_px *end);
int				ca(t_img *img, t_px *bgn, t_px *end);

int				l10(t_img *img, t_px *bgn, t_px *end);
int				l12(t_img *img, t_px *bgn, t_px *end);
int				l14(t_img *img, t_px *bgn, t_px *end);
int				l16(t_img *img, t_px *bgn, t_px *end);
int				l18(t_img *img, t_px *bgn, t_px *end);
int				l1a(t_img *img, t_px *bgn, t_px *end);

int				lt90(t_img *img, t_px *bgn, t_px *end);
int				lt92(t_img *img, t_px *bgn, t_px *end);
int				lt94(t_img *img, t_px *bgn, t_px *end);
int				lt96(t_img *img, t_px *bgn, t_px *end);

int				lb50(t_img *img, t_px *bgn, t_px *end);
int				lb52(t_img *img, t_px *bgn, t_px *end);
int				lb58(t_img *img, t_px *bgn, t_px *end);
int				lb5a(t_img *img, t_px *bgn, t_px *end);

int				b40(t_img *img, t_px *bgn, t_px *end);
int				b42(t_img *img, t_px *bgn, t_px *end);
int				b48(t_img *img, t_px *bgn, t_px *end);
int				b4a(t_img *img, t_px *bgn, t_px *end);

int				t80(t_img *img, t_px *bgn, t_px *end);
int				t82(t_img *img, t_px *bgn, t_px *end);
int				t84(t_img *img, t_px *bgn, t_px *end);
int				t86(t_img *img, t_px *bgn, t_px *end);

#endif
