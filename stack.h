/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:06:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/30 23:27:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct	s_val
{
	int			num;
	int			pos;
}				t_val;

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

int				wrap_swap(t_list **a, t_list **b, char *inst);
int				wrap_put(t_list **a, t_list **b, char *inst);
int				wrap_rotate(t_list **a, t_list **b, char *inst);
int				wrap_rev_rotate(t_list **a, t_list **b, char *inst);

/*
** ##################### UTILS #####################
*/

t_list			*create_stack(int size);
void			del_content(void *content, size_t size);
void			clear2stacks(t_list *a, t_list *b);
int				is_sorted_stack(t_list *stack);
void			print_stack(t_list *stack);
int				get_median(t_list *stack, int size);
int				get_stack_size(t_list *stack);
int				*get_array_nums(t_list *stack, int size);

/*
** ##################### MAIN #####################
*/

int				fill_stack(t_list **stack, char **vals, int size);
void			quick_sort(t_list **a, t_list **b, int size);
void			intqsort(int *src, int start, int end);
void			set_position2val(t_list *stack, int *nums);

#endif
