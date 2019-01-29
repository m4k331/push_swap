#include <stdio.h>
#include "stack.h"


int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = 0;
	fill_stack(&a, ++av, --ac);
	printf("INPUT: ");print_stack(a);printf("\n");
	int pivot = get_pivot(a, ac);
	int r = 0;
	int l = 0;
	t_list *c = a;
	for (int i = 0; i < ac; i++)
	{
		if (*(int*)c->content <= pivot)
			l++;
		else
			r++;
		c = c->next;
	}
	printf("\npivot %d\nleft: %d right %d\n", pivot, l, r);
//	quick_sort(&a, &b, ac);
	printf("\nA: ");print_stack(a);printf("\n");
	printf("B: ");print_stack(b);printf("\n");
	if (is_sorted_stack(a))
		printf("OK\n");
	return (0);
}
