/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:06:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 20:43:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft/includes/libft.h"
# include "src_cr/draw.h"
# include <fcntl.h>
# include <sys/stat.h>

# define CUR		0xCCFF99
# define PRE		0xFFFF99
# define CUR_DWN	0x009900
# define PRE_DWN	0xFFD700
# define DEF_POS	0xFA8072
# define DEF_NEG	0x7FFFD4
# define POS_DWN	0xE8336C
# define NEG_DWN	0x1546E8
# define STACK_BG	0x0036003600360036
# define PANEL_BG	0x0036363600363636

/*
** ################## PS STRUCT #########################
*/

typedef struct	s_ps
{
	t_list		*a;
	t_list		*b;
	t_list		*ins;
	size_t		index;
	int			err;
}				t_ps;

t_ps			*get_newps(t_list *a, t_list *b, t_list *ins);
void			del_ps(t_ps *ps);

/*
** ################## VISUALIZER STRUCT #########################
*/

typedef struct	s_visual
{
	void		*mlx;
	t_win		*win;
	t_img		*img;
	t_img		*panel;
	t_ps		*ps;
	t_vector	**vv;
	size_t		size;
	int			width_sq;
	int			max_height_sq;
	int			mid_line;
	int			max_abs_value;
	int			ins;
	int			sz_ins;
	int			debug;
	int			sorted;
}				t_visual;

/*
** ##################### INSTRUCTIONS #####################
*/

void			swap_stack(t_list **stack);
void			put_stack(t_list **dst, t_list **src);
void			rotate_stack(t_list **stack);
void			rev_rotate_stack(t_list **stack);
int				ins_put(t_ps *ps, char *in);
int				ins_swap(t_ps *ps, char *in);
int				ins_rotate(t_ps *ps, char *in);
int				ins_rev_rotate(t_ps *ps, char *in);

/*
** ####################### UTILS #######################
*/

void			del_content(void *content, size_t size);
void			clear_visual(t_visual *vsr);
void			check_vsr_sorted(t_visual *vsr);
void			check_sorted(t_ps *ps);
void			print_stack(t_list *stack);
void			print_stack_ins(t_list *stack, int fd);
void			print_debug(t_ps *ps, int nbr_ins);
void			apply_ins_cr(t_ps *ps, char *in);
int				get_next_ins(void);
int				is_sorted_stack(t_list *stack);
int				stack_descending(t_list *stack, int size);
int				stack_ascending(t_list *stack, int size);
int				get_median(t_list *stack, int size);
int				partition_a(t_ps *ps, int size);
int				partition_b(t_ps *ps, int size);
int				bt_sort(t_ps *ps, size_t size);
int				insertion_sort(t_ps *ps, int size);
int				del_two_ins(t_ps *ps, int fdel, int sdel);

/*
** ####################### RULES ##############################
*/

void			rarra_rbrrb(t_ps *ps);
void			papb(t_ps *ps);
void			rr(t_ps *ps);
void			rrr(t_ps *ps);
void			ss(t_ps *ps);
void			modify_instruction(t_ps *ps);

/*
** ######################### LOGS #############################
*/

t_vector		**init_color_vv(t_list *lst, size_t init_size);
void			del_vv(t_vector **vv, size_t last);
void			refresh_color_vv(t_list *lst, t_vector **vv);
void			clear_visual(t_visual *vsr);
void			clear_pre_color_vv(t_list *lst, t_vector **vv);

/*
** ########################## KEYS ##############################
*/

int				red_close(void *param);
int				press_key(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);

/*
** ########################## INS VISUALISER ####################
*/

int				ins_vsr_swap(t_ps *ps, t_vector **vv, char *in, int rev);
int				ins_vsr_put(t_ps *ps, t_vector **vv, char *in, int rev);
int				ins_vsr_rot(t_ps *ps, t_vector **vv, char *in, int rev);
int				ins_vsr_rev_rot(t_ps *ps, t_vector **vv, char *in, int rev);
void			vsr_apply_ins(t_visual *vsr);
void			rev_vsr_apply_ins(t_visual *vsr);
void			refresh_panel(t_visual *vsr);

/*
** ########################## MAIN ##############################
*/

int				fill_stack(t_list **stack, char **vals, int size);
int				fill_ins(t_list **ins, char *vals);
void			index_stack(t_list *stack, int size);
int				read_file(t_list **a, char **args, int size);
int				sort(t_ps *ps, int size);
int				throw_ins(t_ps *ps, char flag, int ac, char **av);
char			parse_flags(int *ac, char ***av);
int				parse_nums(t_ps *ps, char flag, int *ac, char ***av);
void			parse_ins(t_ps *ps, char flag, char **av);
void			run_visualization(t_ps *ps, t_vector **vv, size_t size, \
																	char flag);
int				run_debug(t_ps *ps);
void			draw_stacks(t_visual *vsr);
void			init_visual(t_visual *vsr, t_ps *ps, t_vector **vv, \
																size_t size);
int				run_checking(t_ps *ps);

#endif
