#include "../../headers/push_swap.h"

int 	check_input(char *input, const char *max_int) // tested
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if ((int)ft_strlen(input) > 10 + i)
		return (0);
	if ((int)ft_strlen(input) == 10 + i)
	{
		while (input[k + i] && k < 10)
		{
			if (ft_isdigit(input[k + i]) && input[k + i] < max_int[k])
				return (1);
			else
				k++;
		}
		return (0);
	}
	while (input[i] && k == 0)
		k += ft_isdigit(input[i++]);
	return (k > 0);
}

void 	check_all_input(char **input)
{
	int		i;
	int		k;

	i = 0;
	while (input[i])
	{
		k = 0;
		if (check_input(input[i], MAX_INT) == 0)
			error_and_exit("Error");
		while (k < i)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[k]))
				error_and_exit("Error");
			k++;
		}
		i++;
	}
//	if (i < 2)
//		error_and_exit("Error");
}

void 	check_array_size(int argc)
{
	if (argc > MAX_SIZE)
		error_and_exit("Error");
}

void 	array_to_stack(int argc, char **argv, t_item **stack_a)
{
	int		i;
	int		*array;
	int		to_free;

	to_free = 0;
	i = argc - 2;
	if (argc == 2)
	{
		argv[1] = ft_strjoin("x ", argv[1]);
		argv = ft_split(argv[1], ' ');
		argc = split_size(argv);
		i = argc - 2;
		to_free = 1;
	}
	check_array_size(argc);
	check_all_input(argv + 1);
	array = normalize(argc, argv);
	if (to_free == 1)
		free_split(argv);
	while (i >= 0)
	{
		push(stack_a, array[i]);
		i--;
	}
	free(array);
}
