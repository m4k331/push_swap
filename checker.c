/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:39:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/21 00:45:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** The function of executing instructions for stacks
** returns 1 if executed successfully, or 0 if not.
** instructions:
** sa, sb, ss - swap
** pa, pb - put
** ra, rb, rr - rotate
** rra, rrb, rrr - reverse rotate
*/

static int	exec_inst(t_list **a, t_list **b, char *inst)
{
	int		exec;
	size_t	len;

	exec = 0;
	len = ft_strlen(inst);
	if (len == 2)
	{
		if (inst[0] == 's')
			exec = wrap_swap(a, b, inst);
		else if (inst[0] == 'p')
			exec = wrap_put(a, b, inst);
		else if (inst[0] == 'r')
			exec = wrap_rotate(a, b, inst);
	}
	else if (len == 3 && inst[0] == 'r')
		exec = wrap_rev_rotate(a, b, inst);
	return (exec);
}

/*
** The function read stdin and executing instructions for stacks,
** returns 1 if stack a is actually sorted and b is empty,
** returns 0 if stack a is not actually sorted or b is not empty,
** returns -1 otherwise.
*/

static int	valid_input(char *in)
{
	int		valid;

	valid = 1;
	if (in[2] == '\n')
		in[2] = 0;
	else if (in[3] == '\n')
		in[3] = 0;
	else
		valid = 0;
	return (valid);
}

static int	sort_stack(t_list **a, t_list **b)
{
	int		err;
	char	inst[4];
	int		rb;

	err = 0;
	rb = 0;
	while (err == 0 && (rb = read(0, inst, 4)) > 0)
	{
		if (valid_input(inst))
			err = !exec_inst(a, b, inst);
		else
			err = -1;
		ft_memset(inst, 0, rb);
	}
	if (rb == -1 || err == -1)
		return (-1);
	err = !is_sorted_stack(*a);
	err = *b ? 1 : err;
	return (!err);
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

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		state;

	a = 0;
	b = 0;
	state = -1;
	if (ac > 1)
	{
		if (fill_stack(&a, ++av, --ac))
		{
			if ((state = sort_stack(&a, &b)) == 1)
				ft_putstr("OK\n");
			else if (state == 0)
				ft_putstr("KO\n");
			print_stack(a);
			write(1, "\n", 1);
			print_stack(b);
			clear2stacks(a, b);
		}
		if (state == -1)
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
