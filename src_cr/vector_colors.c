/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:25:21 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 23:08:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void				clear_pre_color_vv(t_list *lst, t_vector **vv)
{
	while (lst)
	{
		ft_vpop_back(vv[lst->content_size]);
		lst = lst->next;
	}
}

void				refresh_color_vv(t_list *lst, t_vector **vv)
{
	size_t			iter;
	int				color;

	while (lst)
	{
		iter = lst->content_size;
		color = *(int*)ft_vat(vv[iter], vv[iter]->iter - 1);
		if (color == CUR)
		{
			color = PRE;
			ft_vpush_back(vv[iter], &color, sizeof(int));
		}
		else
		{
			color = (*(int*)lst->content > 0 ? DEF_POS : DEF_NEG);
			ft_vpush_back(vv[iter], &color, sizeof(int));
		}
		lst = lst->next;
	}
}

void				del_vv(t_vector **vv, size_t last)
{
	int				iter;

	iter = (int)last;
	if (vv)
	{
		while (--iter >= 0)
			ft_memdel((void**)vv[iter]);
		ft_memdel((void**)vv);
	}
}

t_vector			**init_color_vv(t_list *lst, size_t init_size)
{
	t_vector		**vv;
	size_t			iter;
	size_t			size;
	int				color;

	iter = 0;
	size = ft_lstsize(lst);
	if ((vv = (t_vector**)malloc(sizeof(t_vector*) * size)))
	{
		while (iter < size)
		{
			if (!(vv[iter] = ft_vnew(init_size, sizeof(int))))
				break ;
			color = (*(int*)lst->content > 0 ? DEF_POS : DEF_NEG);
			ft_vpush_back(vv[iter], &color, sizeof(int));
			iter++;
			lst = lst->next;
		}
		if (iter < size)
			del_vv(vv, iter);
	}
	return (vv);
}
