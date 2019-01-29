/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:29:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/24 23:29:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define EXPAND 2

typedef struct		s_vector
{
	const void		*const_con;
	void			*con;
	size_t			iter;
	size_t			type_size;
	size_t			size;
}					t_vector;

void				ft_verase(t_vector *v);
t_vector			*ft_vnew(size_t v_size, size_t type_size);
void				ft_vresize(t_vector *v, size_t v_size);
void				ft_vpush_back(t_vector *v, void *val, size_t val_size);
void				*ft_vat(t_vector *v, size_t position);
size_t				ft_vmax_size(t_vector *v);
size_t				ft_vsize(t_vector *v);
void				ft_vpop_back(t_vector *v);
size_t				ft_vcapacity(t_vector *v);
void				ft_vreserve(t_vector *v, size_t count);
void				ft_vinsert(t_vector *v, size_t pos, void *src,  size_t cnt);


#endif
