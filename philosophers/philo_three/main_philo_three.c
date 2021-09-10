/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/90 20:25:51 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/90 20:25:51 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philosophers.h"

void	init_process_semaphore(void)
{
	int		i;
	pid_t	pid;

	i = 0;
	sem_unlink(SEM_LOCK);
	sem_unlink(SEM_NAME);
	g_sem_lock = sem_open(SEM_LOCK, O_CREAT, 0777, 1);
	g_sem_forks = sem_open(SEM_NAME, O_CREAT, 0777, g_count);
	if (g_sem_forks == SEM_FAILED || g_sem_lock == SEM_FAILED)
		error_and_exit("semaphore failed");
	while (i < g_count)
	{
		pid = fork();
		if (pid < 0)
			error_and_exit("fork failed");
		g_pid[i] = pid;
		if (pid == CHILD_PROCESS)
		{
			philo_three(i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	kill_all_process(void)
{
	int		i;

	i = 0;
	while (i < MAX_PHILO)
	{
		if (g_pid[i] > 0)
			kill(g_pid[i], SIGKILL);
		i++;
	}
}

void	set_pids_to_zero(void)
{
	int	i;

	i = 0;
	while (i < MAX_PHILO)
	{
		g_pid[i] = -1;
		g_mpid[i] = -1;
		i++;
	}
}

void	wait_philo(void)
{
	int	count;
	int	status;
	int	exit_status;

	count = 0;
	while (count < g_count)
	{
		status = 0;
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status == DEAD)
			{
				break ;
			}
			if (exit_status == ALIVE)
			{
				count++;
			}
		}
	}
}

int		main(int argc, char **argv)
{
	if (get_input(argc, argv) != 0)
		error_and_exit("Wrong parameters");
	init_process_semaphore();
	wait_philo();
	sem_close(g_sem_lock);
	sem_close(g_sem_forks);
	kill_all_process();
	ft_usleep(TIME_TO_WAIT);
	exit(0);
}
