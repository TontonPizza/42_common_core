/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:03:07 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/29 13:03:07 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	grab_fork(t_philo_data *pd)
{
	pthread_mutex_lock(g_forks + (pd->id + ((pd->id + 1) % 2) % g_count));
	display_message_one(get_time_stamp(), pd->id, "has taken a fork");
	pthread_mutex_lock(g_forks + (pd->id + ((pd->id) % 2) % g_count));
	display_message_one(get_time_stamp(), pd->id, "has taken a fork");
}

void		release_forks(t_philo_data *pd)
{
	pthread_mutex_unlock(g_forks + (pd->id + ((pd->id + 1) % 2) % g_count));
	pthread_mutex_unlock(g_forks + (pd->id + ((pd->id) % 2) % g_count));
}

void		action_eat_one(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	grab_fork(pd);
	display_message_one(get_time_stamp(), pd->id, "is eating");
	pd->meal_count++;
	pthread_mutex_lock(&(pd->lock));
	pd->last_lunch = get_time_stamp();
	pthread_mutex_unlock(&(pd->lock));
	wait_and_check(pd, g_time_to_eat);
	release_forks(pd);
}

void		action_sleep_one(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	display_message_one(get_time_stamp(), pd->id, "is sleeping");
	wait_and_check(pd, g_time_to_sleep);
}

void		action_think_one(t_philo_data *pd)
{
	if (pd->status == DEAD)
		return ;
	display_message_one(get_time_stamp(), pd->id, "is thinking");
}
