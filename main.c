/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:18 by auskola-          #+#    #+#             */
/*   Updated: 2023/10/05 08:01:28 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* int is_finished(t_this_philo *philos)
{
		philo->finished = 0;
} */

void	*create_phi(void *thread_data)
{
	t_this_philo	*philo;
	int				i;

	philo = (t_this_philo *)thread_data;
	philo->finished = 0;
	i = 0;
	philo->number_eats = 0;
	philo->eat_time = philo->id % 2;
	philo->my_fork = philo->id;
	philo->left_fork = philo->id - 1;
	if (philo->id == 1)
		philo->left_fork = philo->data->num_philopher;
	if (philo->eat_time == 0)
		usleep(100);
	if (philo->data->number_of_times_eat == 0)
		i = -1;
	while (i < philo->data->number_of_times_eat)
	{
		start_eat(philo);
		i++;
		if (philo->data->number_of_times_eat == 0)
			i = -1;
	}
	philo->finished = 1;
	return (NULL);
}

void	create_threads(t_philoshopher *data)
{
	int				i;
	t_this_philo	*philos;

	philos = (t_this_philo *)malloc(data->num_philopher * sizeof(t_this_philo));
	data->forks = (pthread_mutex_t *)malloc(data->num_philopher * \
	sizeof(pthread_mutex_t));
	i = 0;
	pthread_mutex_init(&data->who_is_now, NULL);
	pthread_mutex_init(&data->can_print, NULL);
	while (i < data->num_philopher)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->filo_start = time_now();
	i = 0;
	while (i < data->num_philopher)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		if (pthread_create(&philos[i].philo, NULL, &create_phi, &philos[i]))
			exit_message("Thread create failure\n");
		i++;
	}
	check_killed(philos);
}

void	one_philo(t_philoshopher *data)
{
	printf("0 ms 1 has taken a fork\n");
	wait_me(data->time_to_die);
	printf("%zu ms 1 died\n", data->time_to_die);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_philoshopher	data;

	if (argc < 5 || argc > 6)
		exit_message("Args failure, must be 4 or 5");
	data.num_philopher = ft_atoi(argv[1]);
	if (data.num_philopher == 0)
		exit(0);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.number_of_times_eat = ft_atoi(argv[5]);
	else
		data.number_of_times_eat = 0;
	data.who_eats = 0;
	if (data.num_philopher == 1)
		one_philo(&data);
	create_threads(&data);
}
