/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _routine_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 09:53:35 by hng          #+#    #+#             */
/*   Updated: 2021/03/89 09:53:35 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ROUTINE_TWO_H
# define A_ROUTINE_TWO_H

# include "../headers/philosophers.h"

void			*philo_two(void *data);

void			action_eat_two(t_philo_data *ts);
void			action_sleep_two(t_philo_data *ts);
void			action_think_two(t_philo_data *ts);
void			display_message_two(unsigned long timestamp, int id, char *msg);
void			release_forks(void);

#endif
