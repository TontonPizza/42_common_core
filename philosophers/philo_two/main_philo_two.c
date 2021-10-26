/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 14:51:00 by hng          #+#    #+#             */
/*   Updated: 2021/03/89 14:51:00 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philosophers.h"

void	init_threads_semaphore(void)
{
	int		i;

	i = 0;
	sem_unlink(SEM_LOCK);
	sem_unlink(SEM_NAME);
	g_all_status = ALIVE;
	g_full_stomach = 0;
	g_discard = 1;
	g_sem_lock = sem_open(SEM_LOCK, O_CREAT, 0777, 1);
	g_sem_forks = sem_open(SEM_NAME, O_CREAT, 0777, g_count);
	if (g_sem_forks == SEM_FAILED)
		error_and_exit("Sempahore failed");
	while (i < g_count)
	{
		g_ids[i] = i;
		pthread_create(&(g_threads[i]), NULL, philo_two, (void *)(&(g_ids[i])));
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (get_input(argc, argv) != 0)
		error_and_exit("Wrong parameters");
	init_threads_semaphore();
	while (i < g_count)
	{
		pthread_detach(g_threads[i]);
		i++;
	}
	while (g_all_status == ALIVE && g_full_stomach != g_count)
		usleep(TOLERANCE * 3);
	ft_usleep(TIME_TO_WAIT);
	sem_close(g_sem_lock);
	sem_close(g_sem_forks);
	return (0);
}
