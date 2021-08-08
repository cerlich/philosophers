/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:25 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/06 20:35:24 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_info(t_philo *ph, int i)
{
	sem_wait(ph->all->out);
	if (i == 1)
		printf("%zu philo %d has taken a fork\n", get_time()
			- ph->start_time, ph->num);
	if (i == 2)
		printf("%zu philo %d is eating\n", get_time()
			- ph->start_time, ph->num);
	if (i == 3)
		printf("%zu philo %d is sleeping\n", get_time()
			- ph->start_time, ph->num);
	if (i == 4)
		printf("%zu philo %d is thinking\n", get_time()
			- ph->start_time, ph->num);
	sem_post(ph->all->out);
}


static void	*end_sim(void *philo)
{
	t_philo	*ph;
	long	t;

	ph = (t_philo *)philo;
	t = ph->all->time_die;
	ph->time_die = get_time();
	while (get_time() - ph->time_die < t)
		usleep(100);
	sem_wait(ph->all->out);
	ph->status = 1;
	ph->all->end_sim = 1;
	printf("%zu philo %d died\n", get_time() - ph->start_time, ph->num);
	kill(ph->pid, SIGTERM);
	//exit(0);
	return (NULL);
}

//static int	start_philo(t_philo	*ph)
//{
//	ph->start_time = ph->all->start_time;
//	if (ph->num % 2 == 0)
//		usleep (100);
//	if (pthread_create(&ph->monitor, NULL, end_sim, ph))
//		return (error(5));
//	if (pthread_detach(ph->monitor))
//		return (error(4));
//	return (0);
//}

static int	philos(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	//if(start_philo(ph))
	//	return (1);	
	if (ph->num % 2 == 0)
		usleep (100);
	ph->start_time = ph->all->start_time;
	if (pthread_create(&ph->monitor, NULL, end_sim, ph))
		return (error(5));
	if (pthread_detach(ph->monitor))
		return (error(4));	
	while (!ph->status)
	{
		sem_wait(ph->all->forks);
		sem_wait(ph->all->forks);
		print_info(ph, 1);
		print_info(ph, 1);
		if (ph->num_meals == -1 || ph->num_meals > 0)
		{
			print_info(ph, 2);
			ph->time_die = get_time();
			ft_usleep(ph->all->time_eat);
			sem_post(ph->all->forks);
			sem_post(ph->all->forks);			
			++ph->eat;
			if (ph->eat >= ph->num_meals && ph->num_meals > 0)
			{
				sem_wait(ph->all->out);
				puts("end simmulation");
				kill(ph->pid, SIGTERM);
			}
			print_info(ph, 3);
			ft_usleep(ph->all->time_sleep);
			print_info(ph, 4);
		}
	}
	return (0);
}

int	start_thread(t_all *a)
{
	int	i;

	i = -1;
	a->start_time = get_time();
	while (++i < a->num_philo)
	{
		a->philo[i].pid = fork();
		if (a->philo[i].pid < 0)
			return(error(3));
		if (a->philo[i].pid == 0)
		{
			if (philos(&a->philo[i]))
				kill(a->philo[i].pid, SIGTERM);
		}
	}
	while (1);
	return (0);
}
