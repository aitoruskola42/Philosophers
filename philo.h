/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:11:29 by auskola-          #+#    #+#             */
/*   Updated: 2023/10/05 08:14:42 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philosopher
{
	int					index;
	char				*name;
	char				*phisolopher;
	int					num_philopher;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					number_of_times_eat;
	int					who_eats;
	int					dead;
	pthread_mutex_t		can_print;
	pthread_mutex_t		who_is_now;
	pthread_mutex_t		print_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		finish_change;
	size_t				filo_start;	
}	t_philoshopher;

typedef struct s_this_pilo
{
	int				id;
	int				eat_time;
	int				left_fork;
	int				my_fork;
	int				number_eats;
	t_philoshopher	*data;
	long int		time_start;
	long int		time_end;
	pthread_t		philo;
	long int		wait_time;
	int				finished;
}	t_this_philo;

int			ft_isdigit(int c);
void		*create_phi(void *data);
void		create_threads(t_philoshopher *data);
size_t		ft_strlen(const char *s);
char		*ft_itoa(int valor);
char		*convert_str(char *str, long n, int numbers, int counter);
int			characters(long n);
int			ft_isscpace(int c);
void		ft_start_atoi(int *numbers);
int			ft_atoi(const char *str);
void		exit_message(char *text);
void		start_eat(t_this_philo *philo);
void		check_killed(t_this_philo *philos);
void		wait_me(size_t time);
size_t		time_now(void);
void		make_philo(int philo_id, t_this_philo *philos);
size_t		time_change(long int start, long int end);
void		check_finished(t_this_philo *philos);
void		check_dead(t_this_philo *philos);
void		print_this(int what, int time, t_this_philo *philo);
#endif