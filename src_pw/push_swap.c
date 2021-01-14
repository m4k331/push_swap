/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:29:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:56:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** Function prints program help
*/

static inline void	print_help(void)
{
	ft_putstr_fd("help: push_swap ints_args ...\n", 2);
	ft_putstr_fd("      push_swap -f src_file_ints\n", 2);
	ft_putstr_fd("      push_swap -f src_file_ints dst_file_ins\n", 2);
	ft_putstr_fd("      push_swap -h (print help)\n", 2);
	exit(1);
}

/*
** Function checking sorted nums
*/

static inline int	nums_is_sorted(t_list *lst)
{
	int				sorted;

	sorted = 1;
	if (lst)
		while (lst->next)
		{
			if (*(int*)lst->content > *(int*)(lst->next)->content && sorted--)
				break ;
			lst = lst->next;
		}
	return (sorted);
}

int					main(int ac, char **av)
{
	t_ps			*ps;
	int				err;
	int				size;
	char			flag;

	err = -1;
	size = 0;
	if ((flag = parse_flags(&ac, &av)) & 8)
		print_help();
	if ((ps = get_newps(0, 0, 0)))
		if (parse_nums(ps, flag, &ac, &av) > -1)
		{
			size = ft_lstsize(ps->a);
			index_stack(ps->a, size);
			if (nums_is_sorted(ps->a))
				err = 1;
			else if (sort(ps, size) != -1)
				err = throw_ins(ps, flag, ac, av);
		}
	del_ps(ps);
	if (err == -1 && size >= 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
