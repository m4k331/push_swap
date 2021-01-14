/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:39:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 23:11:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static inline void	to_number_elems(t_list *lst)
{
	size_t			nbr;

	nbr = 0;
	while (lst)
	{
		lst->content_size = nbr;
		lst = lst->next;
		nbr++;
	}
}

/*
** Function prints program help
*/

static inline void	print_help(void)
{
	ft_putstr_fd("help: checker ints_args ...\n", 2);
	ft_putstr_fd("      checker -f src_file_ints\n", 2);
	ft_putstr_fd("      checker -f src_file_ints dst_file_ins\n", 2);
	ft_putstr_fd("      checker -h (print help)\n", 2);
	ft_putstr_fd("      checker -d (enable debug mode)\n", 2);
	ft_putstr_fd("      checker -v (enable visualization mode)\n", 2);
	exit(0);
}

static inline int	runs(t_ps *ps, t_vector **vv, size_t size, char flag)
{
	int			err;

	err = -1;
	if (flag & 2)
		run_visualization(ps, vv, size, flag);
	else if (flag & 4)
		err = run_debug(ps);
	else
		err = run_checking(ps);
	return (err);
}

static inline char	get_flag(int *ac, char ***av, int *err)
{
	char			flag;

	*err = -1;
	flag = 0;
	if (*ac == 1 || ((flag = parse_flags(ac, av)) & 8))
		print_help();
	return (flag);
}

/*
** Program  will get as an argument the stack a formatted as a list of integers.
** Read instructions and will execute them on the stack received as an argument.
** After executing instructions, stack a is sorted and b is empty, display "OK"
** in every other case, display "KO" on the standard output.
** In case of error, display Error on the standard error.
** Errors include for example: some arguments are not integers;
**							   some arguments are bigger than an integer;
**							   there are duplicates;
**							   an instruction don’t exist or is incorrectly.
*/

int					main(int ac, char **av)
{
	t_ps			*ps;
	t_vector		**vv;
	size_t			size;
	int				err;
	char			flag;

	flag = get_flag(&ac, &av, &err);
	if ((ps = get_newps(0, 0, 0)))
	{
		parse_nums(ps, flag, &ac, &av);
		if (ps->a)
		{
			to_number_elems(ps->a);
			parse_ins(ps, flag, av);
			size = ft_lstsize(ps->a);
			if ((vv = init_color_vv(ps->a, sizeof(int) * 10)) && size && \
																	!ps->err)
				err = runs(ps, vv, size, flag);
			del_vv(vv, size);
			del_ps(ps);
		}
	}
	if (err == -1)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
