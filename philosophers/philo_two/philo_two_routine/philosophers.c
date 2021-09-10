/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 11:28:04 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/89 11:28:04 by vo-nguye         ###   ########.fr       */
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
	while (g_all_status == ALIVE)
	{
		if (pd->meal_count >= g_number_of_meal && g_number_of_meal >= 0)
		{
			g_full_stomach++;
			return (0);
		}
		if (time_since(pd->last_lunch) > (unsigned int)g_time_to_die)
		{
			g_all_status = DEAD;
			display_message_two(get_time_stamp(), pd->id, "is dead");
			g_discard = 0;
			return (0);
		}
		usleep(TOLERANCE);
	}
	return (0);
}

void	*philo_two(void *data)
{
	t_philo_data	pd;
	pthread_t		live_checker;

	pd.id = *(int *)data;
	pd.status = ALIVE;
	pd.meal_count = 0;
	init_time_stamp(&pd);
	ft_usleep((g_time_to_eat / 2) * (pd.id % 2));
	pthread_create(&live_checker, NULL, live_check, (void *)&pd);
	while (g_all_status == ALIVE)
	{
		if (g_number_of_meal >= 0 && pd.meal_count >= g_number_of_meal)
			break ;
		action_eat_two(&pd);
		if (g_number_of_meal >= 0 && pd.meal_count >= g_number_of_meal)
			break ;
		action_sleep_two(&pd);
		action_think_two(&pd);
	}
	pthread_detach(live_checker);
	release_forks();
	while (g_all_status == ALIVE && g_full_stomach != g_count)
		usleep(TOLERANCE);
	return (0);
}
