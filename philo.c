#include "philo.h"

void	init_args(t_all *all)
{
	all->time_die = 0;
	all->time_eat = 0;
	all->num_philo = 0;
	all->num_meals = -1;
	all->time_sleep = 0;
	all->num_forks = 0;
	all->end_sim = 0;
}

void	check_num_meals(t_all *a)
{
	int		i;
	int		count;

	while (!a->end_sim)
	{
		i = -1;
		count = 0;
		while (++i < a->num_philo)
		{
			if (a->philo[i].eat >= a->num_meals)
				count++;
		}
		if (count >= a->num_philo)
		{
			a->end_sim = 1;
			pthread_mutex_lock(a->out);
			printf(
				"%zu all philos has eating at least %d times, end simulation\n",
				get_time(), a->num_meals);
		}
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_all	a;

	init_args(&a);
	if (parse_args(ac, av, &a))
		error(1);
	if (malloc_thread(&a))
		return (1);
	if (a.num_meals > 0)
		check_num_meals(&a);
	while (!a.end_sim)
		usleep(10);
	destroy_mutex(&a);
	return (0);
}
