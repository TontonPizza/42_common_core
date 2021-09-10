/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libraries.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:57:02 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/29 12:57:02 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARIES_STRUCTS_H
# define LIBRARIES_STRUCTS_H

# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>

typedef unsigned long	t_ul;

typedef struct	s_philo_data
{
	t_ul			creation_time;
	t_ul			last_lunch;
	t_ul			last_sleep;
	t_ul			last_think;
	int				id;
	char			status;
	int				meal_count;

	sem_t			slock;
}				t_philo_data;

#endif
