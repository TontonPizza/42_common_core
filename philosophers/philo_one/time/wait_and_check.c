/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 08:59:03 by hng          #+#    #+#             */
/*   Updated: 2021/03/89 08:59:03 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	wait_and_check(t_philo_data *pd, int duration)
{
	long	start;
	long	current;

	start = get_time_stamp();
	current = start;
	while (duration > current - start && pd->status == ALIVE)
	{
		usleep(STEP);
		current = get_time_stamp();
	}
}
