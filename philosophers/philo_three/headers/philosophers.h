/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:57:18 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/29 12:57:18 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libraries_structs.h"

# include "../time/a_time_tools.h"
# include "../input/a_input.h"
# include "../error_management/a_error_management.h"

# include "../philo_three_routine/a_routine_three.h"

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

# ifndef SEM_NAME
#  define SEM_NAME "/sem_fork"
# endif

# ifndef SEM_LOCK
#  define SEM_LOCK "/sem_lock"
# endif

# ifndef TIME_TO_WAIT
#  define TIME_TO_WAIT 1500
# endif

sem_t				*g_sem_forks;
sem_t				*g_sem_lock;

int					g_time_to_eat;
int					g_time_to_sleep;
int					g_time_to_die;
int					g_number_of_meal;
int					g_count;
char				g_all_status;
char				g_all_full;

pthread_t			g_threads[MAX_PHILO];
int					g_ids[MAX_PHILO];
pid_t				g_pid[MAX_PHILO];
pid_t				g_mpid[MAX_PHILO];

#endif
