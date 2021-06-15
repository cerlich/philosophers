#include "philo.h"

int parse_args(int ac, char **av, t_philo *ph)
{
	ph->num_philo = ft_atoi(av[1]);
	ph->die = ft_atoi(av[2]);
	ph->eat = ft_atoi(av[3]);
	ph->sleep = ft_atoi(av[4]);
	if (ph->die < 1 || ph->eat < 1 || ph->num_philo < 1 || ph->sleep < 1)
		return (1);
	if (ac == 6)
	{
		ph->num_times_to_eat = ft_atoi(av[5]);
		if (ph->num_times_to_eat < 1)
			return (1);
	}
	ph->num_forks = ph->num_philo;
	return (0);
}

void init_args(t_philo *av)
{
	av->die = 0;
	av->eat = 0;
	av->num_philo = 0;
	av->num_times_to_eat = 0;
	av->sleep = 0;
	av->num_forks = 0;
}

void philosophers(void *all)
{
	t_all *alls = (t_all *)all;
	printf("%d\n", alls->philo->num_philo);
	return (0);
}

int main(int ac, char **av)
{
	t_philo philo;
	t_all all;
	int status;
	if (ac < 5 || ac > 6)
	{
		printf("Error\n");
		return (0);
	}
	init_args(&philo);
	if(parse_args(ac, av, &philo))
	{
		printf("Error\n");
		return (0);        
	}
	status = pthread_create(all.thread, NULL, philosophers, (void *)&all);
	if (status != 0) {
    	printf("main error: can't create thread, status = %d\n", status);
    	exit(0);
    }
	printf("Hello from main!\n");
	//printf("%d\n%d\n", philo.num_philo, all.philo->die);
	//printf("%d\n", philo.num_philo);
	return (0);
}