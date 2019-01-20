/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:06:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/20 16:39:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"

/*
** ##################### INSTRUCTIONS #####################
*/

void			swap_stack(t_list **stack);
void			put_stack(t_list **a, t_list **b);
void			rotate_stack(t_list **stack);
void			rev_rotate_stack(t_list **stack);

/*
** ##################### WRAPPERS #####################
*/

int				wrap_swap(t_list **a, t_list **b, char *inst)
int				wrap_put(t_list **a, t_list **b, char *inst)
int				wrap_rotate(t_list **a, t_list **b, char *inst)
int				wrap_rev_rotate(t_list **a, t_list **b, char *inst)

/*
** ##################### UTILS #####################
*/

t_list			*create_stack(int size);

/*
** ##################### MAIN #####################
*/

void			fill_stack(t_list **stack, char **vals, int size);

#endif
