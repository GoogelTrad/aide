/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:35:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 15:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_parse(t_global *data, t_philo *philo)
{
	int	i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	while (i < data->philo_nbr)
	{
		philo[i].data = data;
		philo[i].status = 0;
		philo[i].fork = fork;
		pthread_mutex_init(&fork[i], NULL);
		philo[i].philo_n = i + 1;
		philo[i].eat = 0;
		i++;
	}
	return (philo);
}

void	create_philo(t_global *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		printf("i = %d n = %d\n", i, philo[i].philo_n);
		pthread_create(&philo[i].thd, NULL, start_routine, philo + i);
		printf("i = %d n = %d\n", i, philo[i].philo_n);
		i++;
	}
}

int		take_fork(t_philo *philo)
{
	if (philo->philo_n == philo->data->philo_nbr)
		pthread_mutex_lock(&philo->fork[0]);
	else
		pthread_mutex_lock(&philo->fork[philo->philo_n]);
	philo->data->time_today = ft_time_today();
	print_status(philo->data->time_today, philo->philo_n, "has taken a fork\n");
	pthread_mutex_lock(&philo->fork[philo->philo_n - 1]);
	philo->data->time_today = ft_time_today();
	print_status(philo->data->time_today, philo->philo_n, "has taken a fork\n");
	return (0);
}

void	return_fork(t_philo *philo)
{
	if (philo->philo_n == philo->data->philo_nbr)
		pthread_mutex_unlock(&philo->fork[0]);
	else
		pthread_mutex_unlock(&philo->fork[philo->philo_n]);
	pthread_mutex_unlock(&philo->fork[philo->philo_n - 1]);
}
