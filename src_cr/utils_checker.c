/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:34:02 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/08 16:34:02 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void					print_debug(t_ps *ps, int nbr_ins)
{
	ft_putstr(KGRN"Stack A: ");
	print_stack(ps->a);
	ft_putstr(KBLU"\nStack B: ");
	print_stack(ps->b);
	ft_putstr(KRED"\nCurrent ins: ");
	if (nbr_ins > -1)
		ft_putstr((char*)ft_lstat(ps->ins, nbr_ins)->content);
	ft_putstr(KNRM"\n\n");
}

int						get_next_ins(void)
{
	char				buff;

	while (read(0, &buff, 1) > 0)
	{
		if (buff == '\n')
			return (1);
	}
	return (0);
}

void					check_sorted(t_ps *ps)
{
	t_list				*lst;
	int					sorted;

	lst = ps->a;
	sorted = 1;
	if (lst)
		while (lst->next)
		{
			if (*(int*)lst->content > *(int*)(lst->next)->content && sorted--)
				break ;
			lst = lst->next;
		}
	if (sorted && ft_lstsize(ps->b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
