/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:13 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/09 16:02:04 by cerlich          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_all	a;

	init_args(&a);
	if (parse_args(ac, av, &a))
		return (1);
	if (start_thread(&a))
		return (1);
	while (!a.end_sim)
	{
	}
	return (0);
}
