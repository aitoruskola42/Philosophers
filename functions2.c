/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 06:16:22 by auskola-          #+#    #+#             */
/*   Updated: 2023/10/05 06:16:52 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	wait_me(size_t time)
{
	long int	this_time;

	this_time = time_now();
	while ((time_now() - this_time) < time)
		usleep(500);
}

void	start_eat(t_this_philo *philo)
{
	if (philo->time_start == 0)
		philo->time_start = time_now();
	pthread_mutex_lock(&philo->data->forks[philo->my_fork]);
	print_this(1, time_change(philo->data->filo_start, time_now()), philo);
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	print_this(1, time_change(philo->data->filo_start, time_now()), philo);
	if (time_change(philo->time_start, time_now()) > philo->data->time_to_die)
	{
		print_this(2, time_change(philo->time_start, time_now()), philo);
		exit (0);
	}
	philo->time_start = time_now();
	print_this(3, time_change(philo->data->filo_start, time_now()), philo);
	wait_me(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->my_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	print_this(4, time_change(philo->data->filo_start, time_now()), philo);
	wait_me(philo->data->time_to_sleep);
	print_this(5, time_change(philo->data->filo_start, time_now()), philo);
}

void	print_this(int what, int time, t_this_philo *philo)
{
	pthread_mutex_lock(&philo->data->can_print);
	if (what == 1)
		printf("%d ms %d has taken a fork\n", time, philo->id);
	if (what == 2)
		printf("%d ms %d died\n", time, philo->id);
	if (what == 3)
		printf("%d ms %d is eating\n", time, philo->id);
	if (what == 4)
		printf("%d ms %d is sleeping\n", time, philo->id);
	if (what == 5)
		printf("%d ms %d is thinking\n", time, philo->id);
	if (what != 2)
		pthread_mutex_unlock(&philo->data->can_print);
}
