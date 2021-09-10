/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_routine_three.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/90 20:22:19 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/90 20:22:19 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ROUTINE_THREE_H
# define A_ROUTINE_THREE_H

# include "../headers/philosophers.h"

int			philo_three(int id);
void		display_message_three(unsigned long timestamp, int id, char *msg);
void		action_eat_three(t_philo_data *ts);
void		action_sleep_three(t_philo_data *ts);
void		action_think_three(t_philo_data *ts);
void		release_forks(void);

#endif
