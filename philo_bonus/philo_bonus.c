#include "philo.h"

void eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	//pthread_mutex_lock(&ph->all->fork[ph->all->philo->num - 1]);
	printf("%zu philo %d has taken a left fork\n", get_time(), ph->num);
	pthread_mutex_lock(ph->right_fork);
	//pthread_mutex_lock(&ph->all->fork[ph->all->philo->num % ph->all->num_philo]);
	printf("%zu philo %d has taken a right fork\n", get_time(), ph->num);
	ph->time_die = get_time();
	printf("%zu philo %d is eating\n",  get_time(), ph->num);
	if (ph->all->num_meals > 0)
		ph->eat++;
	usleep(ph->all->time_eat * 1000);
	//pthread_mutex_unlock(&ph->all->fork[ph->all->philo->num - 1]);
	//pthread_mutex_unlock(&ph->all->fork[ph->all->philo->num % ph->all->num_philo]);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void *philosophers(void *philo)
{
	t_philo *ph = (t_philo *)philo;
	while(1)
	{
		eating(philo);
		printf("%zu philo %d is sleeping\n",  get_time(), ph->num);
		usleep(ph->all->time_sleep * 1000);
		printf("%zu philo %d is thinking\n", get_time(), ph->num);
	}
	return (NULL);
}

void *end_sim(void *philo)
{
	t_philo *ph = (t_philo *)philo;
	long t;

	t = ph->all->time_die;
	ph->time_die = get_time();
	while (get_time() - ph->time_die <= t)
		usleep(100);
	//pthread_mutex_lock(&ph->all->fork[ph->all->num_forks]);
	printf("%zu philo %d died\n", get_time(), ph->num);
	ph->all->end_sim = 1;
	return (NULL);
}

void *check_meals(void *all)
{
	t_all *a = (t_all *)all;
	int i;
	int num_eat = a->num_meals;
	int count;

	while (1)
	{
		i = -1;
		count = 0;
		while(++i < a->num_philo)
		{
			if (a->philo[i].eat >= num_eat)
				count++;
		}
		if (count >= a->num_philo)
			a->end_sim = 1;
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
	//all.thread_philo = (pthread_t *)malloc(sizeof(pthread_t) * all.num_philo);
	//all.thread_death = (pthread_t *)malloc(sizeof(pthread_t) * all.num_philo);
	if (!all.thread_philo && !all.thread_death)
		error(2);
	i = -1;
	//if (all.num_meals > 0)
	//{
	//	all.thread_meals = (pthread_t *)malloc(sizeof(pthread_t));
	//	if (!all.thread_meals)
	//		error(2);
	//	if (pthread_create(all.thread_meals, NULL, check_meals, &all))
	//		error(3);
	//	if (pthread_detach(*all.thread_meals))
	//		error(4);
	//}
	while (++i < all.num_philo)
	{
		
	}
	while (!all.end_sim)
		usleep(10);
	destroy_mutex(&all);
	if (all.num_meals > 0)
		printf("%zu all philos has eating at least %d times, end simmulation\n", get_time(), all.num_meals);
	//destroy_mutex(&all);
	return (0);
}