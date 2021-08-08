/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:06 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/06 20:31:41 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_all *all)
{
	int	i;

	i = -1;
	all->philo = (t_philo *)malloc(sizeof(t_philo) * all->num_philo);
	if (!all->philo)
		return (error(2));
	while (++i < all->num_philo)
	{
		all->philo[i].num = i + 1;
		all->philo[i].eat = 0;
		all->philo[i].status = 0;
		all->philo[i].time_die = get_time();
		all->philo[i].all = all;
		all->philo[i].num_meals = all->num_meals;
	}
	return (0);
}

static int	check_valid(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
		}
	}
	return (0);
}

int	parse_args(int ac, char **av, t_all *all)
{
	if (ac < 5 || ac > 6)
		return (error(0));
	if (check_valid(av))
		return (1);
	all->num_philo = ft_atoi(av[1]);
	all->time_die = ft_atoi(av[2]);
	all->time_eat = ft_atoi(av[3]);
	all->time_sleep = ft_atoi(av[4]);
	if (all->time_die < 0 || all->time_eat < 0
		|| all->num_philo < 0 || all->time_sleep < 0)
		return (1);
	if (ac == 6)
	{
		all->num_meals = ft_atoi(av[5]);
		if (all->num_meals < 0)
			return (1);
	}
	all->num_forks = all->num_philo;
	sem_unlink("forks");
	sem_unlink("out");
	sem_unlink("num");
	all->forks = sem_open("forks", O_CREAT, 0644, all->num_forks);
	all->out = sem_open("out", O_CREAT, 0644, 1);
	all->meals = sem_open("num", O_CREAT, 0644, all->num_philo);
	if (init_philo(all))
		return (1);
	return (0);
}
