/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hng <hng@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:57:18 by hng          #+#    #+#             */
/*   Updated: 2021/03/29 12:57:18 by hng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libraries_structs.h"

# include "../time/a_time_tools.h"
# include "../input/a_input.h"
# include "../error_management/a_error_management.h"

# include "../philo_one_routine/a_routine_one.h"

# ifndef CHILD_PROCESS
#  define CHILD_PROCESS 0
# endif

# ifndef ALIVE
#  define ALIVE 1
#  define DEAD 0
# endif

# ifndef STEP
#  define STEP 2
# endif

# ifndef TOLERANCE
#  define TOLERANCE 8000
# endif

# ifndef MAX_PHILO
#  define MAX_PHILO 200
# endif

# ifndef TIME_TO_WAIT
#  define TIME_TO_WAIT 1500
# endif

pthread_mutex_t		g_write_lock;

int					g_time_to_eat;
int					g_time_to_sleep;
int					g_time_to_die;
int					g_number_of_meal;
int					g_count;
char				g_all_status;
int					g_full_stomach;
int					g_discard;

pthread_mutex_t		g_forks[MAX_PHILO];
pthread_t			g_threads[MAX_PHILO];
int					g_ids[MAX_PHILO];
pid_t				g_pid[MAX_PHILO];
pid_t				g_mpid[MAX_PHILO];

#endif
