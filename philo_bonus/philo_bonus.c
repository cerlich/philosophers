/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:13 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/06 20:34:14 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_args(t_all *all)
{
	all->time_die = 0;
	all->time_eat = 0;
	all->num_philo = 0;
	all->num_meals = -1;
	all->time_sleep = 0;
	all->num_forks = 0;
	all->end_sim = 0;
}

static void	check_num_meals(t_all *a, int i, int count)
{
	while (1)
	{
		i = -1;
		count = 0;
		while (++i < a->num_philo)
		{
			if (a->philo[i].eat >= a->num_meals)
			{
				a->philo[i].status = 1;
				++count;
			}
			usleep(1000);
		}
		if (count >= a->num_philo)
		{
			a->end_sim = 1;
			sem_wait(a->out);
			printf(
				"%zu all philos has eating at least %d times, end simulation\n",
				get_time() - a->start_time, a->num_meals);
			return ;
		}
		usleep(100000);
	}
}

int	main(int ac, char **av)
{
	t_all	a;

	init_args(&a);
	if (parse_args(ac, av, &a))
		return (1);
	if (start_thread(&a))
		return (1);
	if (a.num_meals > 0)
		check_num_meals(&a, -1, 0);
	while(!a.end_sim);
	free(a.philo);
	return (0);
}
