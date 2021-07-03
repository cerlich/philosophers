#include "philo.h"

static void	*philos(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->left_fork = &ph->all->fork[ph->num - 1];
	ph->right_fork = &ph->all->fork[ph->num % ph->all->num_forks];
	while (1)
	{
		pthread_mutex_lock(ph->left_fork);
		printf("%zu philo %d has taken a left fork\n", get_time(), ph->num);
		pthread_mutex_lock(ph->right_fork);
		printf("%zu philo %d has taken a right fork\n", get_time(), ph->num);
		if (ph->num_meals == -1 || ph->num_meals > 0)
		{
			printf("%zu philo %d is eating\n", get_time(), ph->num);
			ph->time_die = get_time();
			ft_usleep(ph->all->time_eat);
			ph->eat++;
			pthread_mutex_unlock(ph->left_fork);
			pthread_mutex_unlock(ph->right_fork);
			printf("%zu philo %d is sleeping\n", get_time(), ph->num);
			ft_usleep(ph->all->time_sleep);
			printf("%zu philo %d is thinking\n", get_time(), ph->num);
		}
	}
	return (NULL);
}

static void	*end_sim(void *philo)
{
	t_philo	*ph;
	long	t;

	ph = (t_philo *)philo;
	t = ph->all->time_die;
	ph->time_die = get_time();
	while (get_time() - ph->time_die <= t)
		usleep(100);
	pthread_mutex_lock(ph->all->out);
	ph->all->end_sim = 1;
	printf("%zu philo %d died\n", get_time(), ph->num);
	return (NULL);
}

int	malloc_thread(t_all *a)
{
	int	i;

	i = -1;
	a->thread_philo = (pthread_t *)malloc(sizeof(pthread_t) * a->num_philo);
	a->thread_death = (pthread_t *)malloc(sizeof(pthread_t) * a->num_philo);
	if (!a->thread_philo && !a->thread_death)
		return (error(2));
	while (++i < a->num_philo)
	{
		if ((pthread_create(&a->thread_philo[i], NULL, philos, &a->philo[i]))
			|| (pthread_create(&a->thread_death[i],
					NULL, end_sim, &a->philo[i])))
			return (error(3));
		if ((pthread_detach(a->thread_philo[i]))
			|| (pthread_detach(a->thread_death[i])))
			return (error(4));
	}
	return (0);
}
