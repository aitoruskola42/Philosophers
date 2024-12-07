/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:39:59 by auskola-          #+#    #+#             */
/*   Updated: 2023/10/05 08:18:50 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_message(char *text)
{
	printf("%s\n", text);
	exit (0);
}

size_t	time_change(long int start, long int end)
{
	return ((end - start));
}

void	check_finished(t_this_philo *philos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (philos[0].data->number_of_times_eat > 0)
	{
		i = 0;
		while (i < philos[0].data->num_philopher)
		{
			if (philos[i].finished == 1)
				j++;
			i++;
		}
		if (j == philos[0].data->num_philopher)
		{
			wait_me(10);
			exit (0);
		}
	}
}

void	check_dead(t_this_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num_philopher)
	{
		if (time_change(philos[i].time_start, time_now()) > \
		philos[i].data->time_to_die && philos[i].finished == 0)
		{
			printf("%ld ms %d died\n", \
			time_change(philos[i].time_start, time_now()), philos[i].id);
			exit (0);
		}
		i++;
	}
}

void	check_killed(t_this_philo *philos)
{
	wait_me(philos[0].data->time_to_eat);
	while (1)
	{
		wait_me(400);
		check_finished(philos);
		check_dead(philos);
	}
}
