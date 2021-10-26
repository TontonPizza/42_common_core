/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/88 14:23:01 by hng          #+#    #+#             */
/*   Updated: 2021/03/88 14:23:01 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philosophers.h"

void	init_threads_mutex(void)
{
	int		i;

	i = 0;
	g_all_status = ALIVE;
	g_full_stomach = 0;
	g_discard = 1;
	while (i < g_count)
	{
		g_ids[i] = i;
		pthread_mutex_init(g_forks + i, 0);
		pthread_create(&(g_threads[i]), NULL, philo_one, (void *)(&(g_ids[i])));
		i++;
	}
	i = 0;
}

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (get_input(argc, argv) != 0)
		error_and_exit("Wrong parameters");
	if (pthread_mutex_init(&g_write_lock, 0) != 0)
		error_and_exit("mutex init failed\n");
	init_threads_mutex();
	while (i < g_count)
	{
		pthread_detach(g_threads[i]);
		i++;
	}
	while (g_all_status == ALIVE && g_full_stomach != g_count)
		usleep(TOLERANCE * 3);
	i = 0;
	while (i < g_count)
		pthread_mutex_destroy(g_forks + i++);
	ft_usleep(TIME_TO_WAIT);
	return (0);
}
