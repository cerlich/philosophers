#include "philo.h"

void sleeping(t_philo *ph)
{
	printf("%zu philo %d is sleeping\n",  get_time(), ph->num);
	usleep(ph->all->time_sleep * 1000);
}

void eating(t_philo *ph)
{
	printf("%zu philo %d has taken a fork\n", get_time(), ph->num);
	printf("%zu philo %d is eating\n",  get_time(), ph->num);
	usleep(ph->all->time_eat * 1000);
}

void *philosophers(void *philo)
{
	t_philo *ph = (t_philo *)philo;
	while(1)
	{
		eating(philo);
		sleeping(philo);
		printf("%zu philo %d is thinking\n", get_time(), ph->num);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_all all;
	int i;

	i = -1;
	if (ac < 5 || ac > 6)
		error(0);
	init_args(&all);
	if(parse_args(ac, av, &all))
		error(1);        
	all.thread = (pthread_t *)malloc(sizeof(pthread_t) * all.num_philo);
	if (!all.thread)
		error(2);
	while (++i < all.num_philo)
	{
		if (pthread_create(&all.thread[i], NULL, philosophers, &all.philo[i]))
			error(3);
		if (pthread_detach(all.thread[i]))
			error(4);
	}
	while (1)
		usleep(10);
	return (0);
}