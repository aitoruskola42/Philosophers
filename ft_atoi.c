/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:30:27 by auskola-          #+#    #+#             */
/*   Updated: 2023/10/05 08:20:00 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	sign = 1;	option[0]
	number = 0;	option[1]
	checked = 0;		option[2]
*/
#include "philo.h"

int	ft_isscpace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f' || \
	c == '\r' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

void	ft_start_atoi(int *numbers)
{
	numbers[0] = 1;
	numbers[1] = 0;
	numbers[2] = 0;
}

int	ft_atoi(const char *str)
{
	size_t	counter;
	int		option[3];

	ft_start_atoi (option);
	counter = -1;
	while (++counter < ft_strlen(str))
	{
		if ((str[counter] == '-' || str[counter] == '+') && option[2] == 0)
		{
			option[2] = 1;
			if (str[counter] == '-')
				option[0] = -1;
		}
		else if (ft_isscpace(str[counter]) && option[2])
			return (option[0] * option[1]);
		else if (ft_isdigit (str[counter]))
		{
			option[2] = 1;
			option[1] = option[1] * 10 + (str[counter] - '0');
		}
		else if (ft_isscpace(str[counter]) < 1)
			return (option[0] * option[1]);
	}
	return (option[0] * option[1]);
}
