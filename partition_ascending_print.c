#include "stack.h"
#include <stdio.h>

static int count = 0;

static int	elem_more_range(t_list *a, t_list *b, int b_range)
{
	int		more;

	more = 1;
	if (!a || !b)
		return (more);
	while (b && b_range--)
	{
		if (*(int*)b->content > *(int*)a->content)
		{
			more = 0;
			break ;
		}
		b = b->next;
	}
	return (more);
}

static int	stack_ascending(t_list *stack, int size)
{
	int		ascending;
	t_list	*previous;

	ascending = 1;
	previous = stack;
	if (!stack)
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
	if (!stack)
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

static int	get_stack_size(t_list *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	less_median(t_list *stack, int median, int size, int rot)
{
	int		less;
	t_list	*head;
	int		stack_size;

	less = 0;
	head = stack;
	stack_size = get_stack_size(stack);
	if (!stack)
		return (less);
	while (stack && --size > -1)
	{
		if (*(int*)stack->content < median)
		{
			less = 1;
			break ;
		}
		stack = stack->next;
	}
	if (!less)
	{
		stack_size = (stack_size > rot ? stack_size - rot : 0);
		while (head && --stack_size > 0)
				head = head->next;
		while (head)
		{
			if (*(int*)head->content < median)
			{
				less = 1;
				break ;
			}
			head = head->next;
		}
	}
	return (less);
}

static int	more_median(t_list *stack, int median, int size, int rot)
{
	int		more;
	t_list	*head;
	int		stack_size;

	more = 0;
	head = stack;
	stack_size = get_stack_size(stack);
	if (!stack)
		return (more);
	while (stack && --size > -1)
	{
		if (*(int*)stack->content > median)
		{
			more = 1;
			break ;
		}
		stack = stack->next;
	}
	if (!more)
	{
		stack_size = (stack_size > rot ? stack_size - rot : 0);
		while (head && --stack_size > 0)
				head = head->next;
		while (head)
		{
			if (*(int*)head->content > median)
			{
				more = 1;
				break ;
			}
			head = head->next;
		}
	}
	return (more);
}

static int	right_sort(t_list **a, t_list **b, int size)
{
	int		iter;
	int		median;
	int		put;
	int		rot;

	iter = size;
	median = get_median(*a, size);
	put = 0;
	rot = 0;
	printf("\nright_median:%d size:%d\n", median, size);
	printf("A: ");print_stack(*a);printf("\n");
	printf("B: ");print_stack(*b);printf("\n\n");
	if (!size || stack_ascending(*a, iter))
		return (0);
	if (size == 2 || size == 3)
	{
		swap_stack(a);
		count++;
		if (stack_ascending(*a, size))
		{
			printf("swp A: "); print_stack(*a);printf("\n");
			return (0);
		}
		swap_stack(a);
		count--;
	}
	while ((!stack_ascending(*a, iter) ||  \
			less_median(*a, median, size - put - rot, rot)) && iter-- && ++count)
	{
		if (*(int*)(*a)->content < median)
		{
			put_stack(b, a);
			put++;
			printf("put A: "); print_stack(*a);printf("\n");
			printf("    B: "); print_stack(*b);printf("\n");
		}
		else 
		{
			rotate_stack(a);
			rot++;
			printf("rot A: "); print_stack(*a);printf("\n");
		}
	}
	while (rot-- > 0)
	{
		rev_rotate_stack(a);
		printf("rev_rot A: "); print_stack(*a);printf("\n");
		count++;
	}
	put += right_sort(a, b, size - put);
	return (put);
}
/*
static void	left_sort(t_list **a, t_list **b, int size)
{
	int		iter;
	int		median;
	int		put;
	int		rot;

	iter = size;
	median = get_median(*b, size);
	put = 0;
	rot = 0;
	printf("\nleft_median:%d size:%d\n", median, size);
	printf("A: ");print_stack(*a);printf("\n");
	printf("B: ");print_stack(*b);printf("\n\n");
	if (!size)
		return ;
	if (size == 1)
	{
		put_stack(a, b);
		put++;
		iter--;
		count++;
		if (!stack_ascending(*a, size + 1))
			right_sort(a, b, size + 1);
		printf("put A: "); print_stack(*a);printf("\n");
		printf("    B: "); print_stack(*b);printf("\n");
	}
	if (size == 2 || size == 3)
	{
		swap_stack(b);
		if (stack_descending(*b, size))
		{
			count++;
			printf("swp B: "); print_stack(*b);printf("\n");
		}
		else
			swap_stack(b);
	}
	while ((!stack_descending(*b, iter) || \
			more_median(*b, median, size - put - rot, rot)) && iter-- && ++count)
	{
		if (*(int*)(*b)->content > median)
		{
			put_stack(a, b);
			put++;
			printf("put A: "); print_stack(*a);printf("\n");
			printf("    B: "); print_stack(*b);printf("\n");
		}
		else
		{
			rotate_stack(b);
			rot++;
			printf("rot B: "); print_stack(*b);printf("\n");
		}
	}
	while (rot-- > 0)
	{
		rev_rotate_stack(b);
		printf("rev_rot B: "); print_stack(*b);printf("\n");
		count++;
	}
	if (stack_ascending(*a, size))
		left_sort(a, b, size - put);
	else
		left_sort(a, b, size - put + right_sort(a, b, put));
}
*/
static void	swap_ascending(t_list **stack, int size)
{
	swap_stack(stack); count++;
	if (stack_ascending(*stack, size))
		return ;
	swap_stack(stack); count--;
}

/*
** Returns amount put elements in stack b
*/

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
	printf("PIVOT:%d\n", pivot);
	while (--iter)
		if (!stack_ascending(*a, size - put) || *(int*)(*a)->content < pivot)
		{
			if (iter == 2 || iter == 3)
				swap_ascending(a, size);
			if (*(int*)(*a)->content < pivot && ++put)
			{
				put_stack(b, a); count++;
				printf("[%d]put B: ", iter); print_stack(*b);printf("\n");
				printf("    A: "); print_stack(*a);printf("\n");
			}
			else if (++rot)
			{
				rotate_stack(a); count++;
				printf("[%d]rot A: ", iter); print_stack(*a);printf("\n");
			}
		}
	while (rot--)
	{
		rev_rotate_stack(a); count++;
		printf("rev_rot A: "); print_stack(*a);printf("\n");
	}
	return (put);
}

void		quick_sort(t_list **a, t_list **b, int size)
{
	int		pivot;
	int		iter;
	int		put;
/*
	pivot = get_median(*a, size);
	put = 0;
	iter = size;
	if (stack_ascending(*a, size))
		return ;
	if (size == 2 || size == 3)
		swap_ascending(a, size);
	while (iter--)
	{
		if (stack_ascending(*a, iter) && elem_more_range(*a, *b, size))
			break ;
		if (*(int*)(*a)->content <= pivot && ++put && ++count)
			put_stack(b, a);
		else
			rotate_stack(a);
	}
	quick_sort(a, b, size - put);
	printf("A: "); print_stack(*a);printf("\n");
	printf("B: "); print_stack(*b);printf("\n");
*/
	printf("\n PARTITION ASCENDING:%d\n", partition_ascending(a, b, size));
//	left_sort(a, b, put);
}
