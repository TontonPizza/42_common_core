/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/90 20:22:36 by hng          #+#    #+#             */
/*   Updated: 2021/03/90 20:22:36 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	init_time_stamp(t_philo_data *ts)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ts->creation_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ts->last_lunch = ts->creation_time;
	ts->last_sleep = ts->creation_time;
	ts->last_think = ts->creation_time;
}

void	*live_check(void *data)
{
	t_philo_data *pd;

	pd = (t_philo_data *)data;
	while (pd->status == ALIVE)
	{
		if (pd->meal_count >= g_number_of_meal && g_number_of_meal >= 0)
			break ;
		if (time_since(pd->last_lunch) > (unsigned int)g_time_to_die)
		{
			pd->status = DEAD;
			display_message_three(get_time_stamp(), pd->id, "is dead");
			exit(DEAD);
		}
		usleep(TOLERANCE);
	}
	return (0);
}

int		philo_three(int id)
{
	t_philo_data	pd;
	pthread_t		live_checker;

	pd.id = id;
	pd.status = ALIVE;
	pd.meal_count = 0;
	init_time_stamp(&pd);
	ft_usleep((g_time_to_eat / 2) * (pd.id % 2));
	sem_open(SEM_NAME, O_RDWR);
	sem_open(SEM_LOCK, O_RDWR);
	pthread_create(&live_checker, NULL, live_check, (void *)&pd);
	pthread_detach(live_checker);
	while (pd.status == ALIVE)
	{
		if (g_number_of_meal >= 0 && pd.meal_count >= g_number_of_meal)
			break ;
		action_eat_three(&pd);
		if (g_number_of_meal >= 0 && pd.meal_count >= g_number_of_meal)
			break ;
		action_sleep_three(&pd);
		action_think_three(&pd);
	}
	release_forks();
	exit(pd.status);
}
