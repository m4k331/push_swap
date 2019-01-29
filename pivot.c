#include "stack.h"
#include "libft.h"

unsigned int		myrnd(int seed, int range)
{
	unsigned int	state0;
	unsigned int	state1;
	unsigned int	rnd;

	seed = seed ? seed : 2412;
	range = range ? range : 1;
	state0 = seed;
	state1 = range;
	state0 = 18030 * (state0 & 0xffff) + (state0 >> 16);
	state1 = 30903 * (state1 & 0xffff) + (state1 >> 16);
	rnd = (state0 << 16) + (state1 & 0xffff);
	while (rnd > range)
		rnd = rnd >> 1;
	return (rnd);
}

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

static int	get_min_value(int *nums, int size)
{
	int		min;

	min = *nums;
	while (--size > 0)
	{
		nums++;
		if (*nums < min)
			min = *nums;
	}
	return (min);
}

static int	partition(int *nums, int size, int wall)
{
	int		left;
	int		right;

	left = 0;
	right = 0;
	while (right < size)
	{
		if (nums[right] <= wall)
		{
			swap(&nums[left], &nums[right], sizeof(int));
			left++;
		}
		right++;
	}
	printf("LLLL  %d nums[l]=%d\n", left, nums[left - 1]);
	if (left == size)
		left = partition(nums, size, nums[size / 2]);
	return (left - 1);
}

static int	quickselect(int *nums, int size, int k)
{
	int		part;

	printf("[%d]subarray: ", k);
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
	part = partition(nums, size, nums[0]);
	printf("[%dMNMNMN: ", k);
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");

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
	printf(">>>subarray: ");
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
	printf("size: %d k: %d part: %d\n\n", size, k, part);
	return (quickselect(nums, size, k));
}

static int	get_avg(t_list *stack, int size)
{
	ssize_t	sum;
	int		count;

	sum = 0;
	count = size;
	if (!size || !stack)
		return (sum);
	while (stack && count--)
	{
		sum += *(int*)stack->content;
		stack = stack->next;
	}
	return (sum / size);
}

int			get_pivot(t_list *stack, int size)
{
	int		*nums;
	int		pivot;
	int		mid;

	nums = (stack ? get_array_nums(stack, size) : 0);
	
	mid = (size % 2 == 1 ? size / 2 + 1 : size / 2);
	if (nums)
	{
		pivot = quickselect(nums, size, mid);
		printf("WTF:%d", pivot);
		free(nums);
	}
	else
		pivot = get_avg(stack, size);
	return (pivot);
}
