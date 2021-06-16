#include "philo.h"

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

void *philosophers(void *all)
{
	//puts("1");
	t_all *alls = (t_all *)all;
	//puts("1");
	//printf("tread %d\n", alls->num_philo);
	//puts("wewewe");
	return (0);
}

int main(int ac, char **av)
{
	t_all all;
	int status;
	int status_addr;
	//if (ac < 5 || ac > 6)
	//{
	//	printf("Error\n");
	//	return (0);
	//}
	//init_args(&all);
	//if(parse_args(ac, av, &all))
	//{
	//	printf("Error\n");
	//	return (0);        
	//}
	//puts("1");
	all.thread = (pthread_t *)malloc(sizeof(pthread_t));
	status = pthread_create(all.thread, NULL, philosophers, (void *)&all);
	if (status != 0) {
    	printf("main error: can't create thread, status = %d\n", status);
    	exit(0);
    }
	printf("Hello from main!\n");
	status = pthread_join(*all.thread, (void**)&status_addr);
    if (status != 0) {
        printf("main error: can't join thread, status = %d\n", status);
        exit(0);
    }
    printf("joined with address %d\n", status_addr);
	//printf("%d\n%d\n", philo.num_philo, all.philo->die);
	//printf("%d\n", philo.num_philo);
	return (0);
}