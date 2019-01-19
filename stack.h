/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:06:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 16:33:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"

/*
** ##################### INSTRUCTIONS #####################
*/

void			swap_stack(t_list **stack);
void			push_stack(t_list **a, t_list **b);
void			rotate_stack(t_list **stack);
void			rev_rotate_stack(t_list **stack);

#endif
