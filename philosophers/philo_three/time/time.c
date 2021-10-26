/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:58:05 by hng          #+#    #+#             */
/*   Updated: 2021/03/29 12:58:05 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	ft_usleep(int duration)
{
	long	start;
	long	current;

	start = get_time_stamp();
	current = start;
	while (duration > current - start)
	{
		usleep(STEP);
		current = get_time_stamp();
	}
}

t_ul	get_time_stamp(void)
{
	struct timeval	tv;
	t_ul			current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (current_time);
}

t_ul	time_since(t_ul time_stamp)
{
	return (get_time_stamp() - time_stamp);
}
