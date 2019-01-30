#include "stack.h"
#include "libft.h"

void				swap(void *a, void *b, int size)
{
	unsigned char	*pa;
	unsigned char	*pb;
	unsigned char	tmp;

	pa = a;
	pb = b;
	while (size--)
	{
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
		pa++;
		pb++;
	}
}

static int	*get_array_nums(t_list *stack, int size)
{
	int		*nums;
	int		iter;

	iter = 0;
	if ((nums = (int*)malloc(sizeof(int) * size)))
	{
		while (stack && size--)
		{
			nums[iter++] = *(int*)stack->content;
			stack = stack->next;
		}
	}
	return (nums);
}

static int	partition(int *nums, int size)
{
	int		left;
	int		right;
	int		wall;

	left = 0;
	right = size - 1;
	wall = 0;
	while (left != right)
	{
		if (nums[left] <= nums[wall])
		{
			swap(&nums[left], &nums[wall], sizeof(int));
			wall = left;
			left++;
		}
		else
		{
			while (nums[right] > nums[wall] && right != left)
				right--;
			swap(&nums[left], &nums[right], sizeof(int));
		}
	}
	return (wall);
}

static int	quickselect(int *nums, int size, int k)
{
	int		part;

	part = partition(nums, size);
	if (part == k - 1)
		return (nums[part]);
	if (part > k - 1)
		size = part + 1;
	else
	{
		k -= part + 1;
		nums += part + 1;
		size -= part + 1;
	}
	return (quickselect(nums, size, k));
}

static int	bruteforce(t_list *stack, int k)
{
	t_list	*head;
	t_list	*iter;
	int		count;

	head = stack;
	count = 0;
	while ((iter = head))
	{
		while (iter)
		{
			if (*(int*)iter->content <= *(int*)stack->content)
				count++;
			iter = iter->next;
		}	
		if (count == k || !(stack = stack->next))
			break ;
		count = 0;
	}
	return (*(int*)stack->content);
}

int			get_median(t_list *stack, int size)
{
	int		*nums;
	int		median;
	int		k;

	if (!size)
		return (0);
	nums = (stack ? get_array_nums(stack, size) : 0);
	k = (size % 2 == 1 ? size / 2 + 1 : size / 2);
	if (nums)
	{
		median = quickselect(nums, size, k);
		free(nums);
	}
	else
		median = bruteforce(stack, k);
	return (median);
}
