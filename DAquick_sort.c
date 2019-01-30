#include "stack.h"

static int	stack_ascending(t_list *stack, int size)
{
	int		ascending;
	t_list	*previous;

	ascending = 1;
	previous = stack;
	if (!stack || !size)
		return (ascending);
	while (stack->next && --size > 0)
	{
		stack = stack->next;
		if (*(int*)previous->content > *(int*)stack->content)
		{
			ascending = 0;
			break ;
		}
		previous = stack;
	}
	return (ascending);
}

static int	stack_descending(t_list *stack, int size)
{
	int		descending;
	t_list	*previous;

	descending = 1;
	previous = stack;
	if (!stack || !size)
		return (descending);
	while (stack->next && --size > 0)
	{
		stack = stack->next;
		if (*(int*)previous->content < *(int*)stack->content)
		{
			descending = 0;
			break ;
		}
		previous = stack;
	}
	return (descending);
}

static void	swap_ascending(t_list **stack, int size)
{
	swap_stack(stack);
	if (stack_ascending(*stack, size))
		return ;
	swap_stack(stack);
}

static void	swap_descending(t_list **stack, int size)
{
	swap_stack(stack);
	if (stack_descending(*stack, size))
		return ;
	swap_stack(stack);
}

int			partition_ascending(t_list **a, t_list **b, int size)
{
	int		iter;
	int		rot;
	int		put;
	int		pivot;

	if (size == 0 || size == 1 || stack_ascending(*a, size))
		return (0);
	rot = 0;
	put = 0;
	iter = size + 1;
	pivot = get_median(*a, size);
	while (--iter)
		if (!stack_ascending(*a, size - put) || *(int*)(*a)->content < pivot)
		{
			if (iter == 2 || iter == 3)
				swap_ascending(a, size);
			if (*(int*)(*a)->content < pivot && ++put)
				put_stack(b, a);
			else if (++rot)
				rotate_stack(a);
		}
	while (rot--)
		rev_rotate_stack(a);
	return (put);
}

int			partition_descending(t_list **a, t_list **b, int size)
{
	int		iter;
	int		rot;
	int		put;
	int		pivot;

	if (size == 0)
		return (0);			
	rot = 0;
	put = 0;
	iter = size + 1;
	pivot = get_median(*b, size);
	while (--iter)
	{
		if (!stack_descending(*b, size) && (iter == 2 || iter == 3))
			swap_descending(b, size);
		if (*(int*)(*b)->content >= pivot && ++put)
			put_stack(a, b);
		else if (++rot)
			rotate_stack(b);
	}
	while (rot--)
		rev_rotate_stack(b);
	return (put);
}

static int	right_sort(t_list **a, t_list **b, int size)
{
	int		put;

	put = partition_ascending(a, b, size);
	size -= put;
	if (!stack_ascending(*a, size))
		put += right_sort(a, b, size);
	return (put);
}

static void	left_sort(t_list **a, t_list **b, int size)
{
	int		put;

	if (size == 0)
		return ;
	put = partition_descending(a, b, size);
	size -= put;
	if (stack_ascending(*a, put) && stack_descending(*b, size))
		left_sort(a, b, size);
	else
		left_sort(a, b, size + right_sort(a, b, put));
}

void		quick_sort(t_list **a, t_list **b, int size)
{
	int		pivot;
	int		iter;
	int		put;

	pivot = get_median(*a, size);
	put = 0;
	iter = size;
	if (!size || stack_ascending(*a, size))
		return ;
	if (size == 2 || size == 3)
		swap_ascending(a, size);
	while (!stack_ascending(*a, size - put) && iter--)
	{
		if (stack_ascending(*a, size - put) && *(int*)(*a)->content >= pivot)
			break ;
		if (*(int*)(*a)->content < pivot && ++put)
			put_stack(b, a);
		else
			rotate_stack(a);
	}
	if (!stack_ascending(*a, size - put))
		quick_sort(a, b, size - put);
	left_sort(a, b, put);
}
