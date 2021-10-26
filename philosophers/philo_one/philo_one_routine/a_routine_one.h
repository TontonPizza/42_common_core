/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 09:00:08 by hng          #+#    #+#             */
/*   Updated: 2021/03/89 09:00:08 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ROUTINE_ONE_H
# define A_ROUTINE_ONE_H

# include "../headers/philosophers.h"

void			*philo_one(void *data);
void			action_eat_one(t_philo_data *ts);
void			action_sleep_one(t_philo_data *ts);
void			action_think_one(t_philo_data *ts);
void			display_message_one(unsigned long timestamp, int id, char *msg);
void			release_forks(t_philo_data *pd);

#endif
