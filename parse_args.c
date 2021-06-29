#include "philo.h"

int init_mutex(t_all *all)
{
	int i;

	i = -1;
	all->fork = (t_mute *)malloc(sizeof(t_mute) * all->num_forks);
	if (!all->fork)
		error(2);
	while(++i < all->num_forks)
		pthread_mutex_init(&all->fork[i], NULL);
	return (0);
}

int init_philo(t_all *all)
{
    int i;

    i = -1;
    all->philo = (t_philo *)malloc(sizeof(t_philo) * all->num_philo);
	if (!all->philo)
		error(2);
    while (++i < all->num_philo)
    {
        all->philo[i].num = i + 1;
        if (all->num_meals > 1)
            all->philo[i].num_meals = all->num_meals;
        all->philo[i].eat = all->time_eat;
        all->philo[i].time_die = all->time_die;
		all->philo[i].all = all;
    }
    return (0);
}

int parse_args(int ac, char **av, t_all *all)
{
	all->num_philo = ft_atoi(av[1]);
	all->time_die = ft_atoi(av[2]);
	all->time_eat = ft_atoi(av[3]);
	all->time_sleep = ft_atoi(av[4]);
	if (all->time_die < 1 || all->time_eat < 1 || all->num_philo < 1 || all->time_sleep < 1)
		return (1);
	if (ac == 6)
	{
		all->num_meals = ft_atoi(av[5]);
		if (all->num_meals < 1)
			return (1);
	}
	all->num_forks = all->num_philo;
    init_philo(all);
	init_mutex(all);
	return (0);
}

void init_args(t_all *all)
{
	all->time_die = 0;
	all->time_eat = 0;
	all->num_philo = 0;
	all->num_meals = 0;
	all->time_sleep = 0;
	all->num_forks = 0;
}