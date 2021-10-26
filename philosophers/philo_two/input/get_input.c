/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/88 14:19:58 by hng          #+#    #+#             */
/*   Updated: 2021/03/88 14:19:58 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int		ph_atoi(char *word)
{
	int		i;
	int		cursor;

	i = 0;
	cursor = 0;
	while (word[cursor])
	{
		i = i * 10 + word[cursor] - '0';
		cursor++;
	}
	return (i);
}

int		input_is_legit(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] > '9' || input[i] < '0')
			return (0);
		i++;
	}
	if (i > 8)
		return (0);
	return (1);
}

int		get_input(int argc, char **argv)
{
	int		i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (input_is_legit(argv[i++]) != 1)
			return (2);
	}
	g_count = ph_atoi(argv[1]);
	g_time_to_die = ph_atoi(argv[2]);
	g_time_to_eat = ph_atoi(argv[3]);
	g_time_to_sleep = ph_atoi(argv[4]);
	if (argc == 6)
		g_number_of_meal = ph_atoi(argv[5]);
	else
		g_number_of_meal = -1;
	if (g_time_to_die < 0 || g_time_to_eat < 0 || g_time_to_sleep < 0)
		return (3);
	if (g_count < 1 || g_count >= MAX_PHILO)
		return (4);
	return (0);
}
