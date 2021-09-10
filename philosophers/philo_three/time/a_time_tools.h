/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _time_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/89 08:30:51 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/89 08:30:51 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_TIME_TOOLS_H
# define A_TIME_TOOLS_H

# include "../headers/philosophers.h"

t_ul	get_time_stamp(void);
t_ul	time_since(t_ul time_stamp);
void	wait_and_check(t_philo_data *pd, int time_to_wait);
void	ft_usleep(int duration);

#endif
