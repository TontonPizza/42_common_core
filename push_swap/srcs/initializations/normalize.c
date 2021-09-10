#include "../../headers/push_swap.h"

void 	bubble_sort(int size, int *array)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int 	*normalize_2(int size, int *raw, int *ordered)
{
	int		*normalized;
	int		i;
	int		k;

	normalized = x_malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size && ordered[k] != raw[i])
			k++;
		normalized[i] = k;
		i++;
	}
	i = 0;
	free(raw);
	free(ordered);
	return (normalized);
}

int 	*normalize(int argc, char **argv)
{
	int		*raw_numbers;
	int		*ordered_numbers;
	int		i;

	raw_numbers = x_malloc(sizeof(int) * (argc));
	ordered_numbers = x_malloc(sizeof(int) * (argc));
	i = 0;
	while (i < argc && argv[i + 1])
	{
		raw_numbers[i] = ft_atoi(argv[i + 1]);
		ordered_numbers[i] = raw_numbers[i];
		i++;
	}
	bubble_sort(argc - 1, ordered_numbers);
	return (normalize_2(argc - 1, raw_numbers, ordered_numbers));
}
