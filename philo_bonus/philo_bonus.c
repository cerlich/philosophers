/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:13 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/06 20:34:14 by cerlich          ###   ########.fr       */
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

//static void kill_proc(t_all *a)
//{
//	a->end_sim = 1;
//	sem_wait(a->out);
//	printf(
//		"%zu all philos has eating at least %d times, end simulation\n",
//		get_time() - a->start_time, a->num_meals);
//	kill(a->philo->pid, SIGTERM);	
//}

//static void	*check_num_meals(void *all)
//{
//	t_all *a;
//
//	a = (t_all *)all;
//	int val;
//	while (!a->end_sim)
//	{
//		sem_getvalue(a->meals, &val);
//		if (val == 0)
//		{
//			a->end_sim = 1;
//			sem_wait(a->out);
//			printf(
//			"%zu all philos has eating at least %d times, end simulation\n",
//				get_time() - a->start_time, a->num_meals);
//			kill(a->philo->pid, SIGTERM);			
//		}
//		usleep(1000);
//		//if (count >= a->num_philo)
//		//{
//			//kill_proc(a);
//			///a->end_sim = 1;
//			///sem_wait(a->out);
//			///printf(
//			///	"%zu all philos has eating at least %d times, end simulation\n",
//			///	get_time() - a->start_time, a->num_meals);
//			///kill(a->philo->pid, SIGTERM);
//		//}
//		//usleep(100000);
//	}
//	return (NULL);
//}

int	main(int ac, char **av)
{
	t_all	a;

	init_args(&a);
	if (parse_args(ac, av, &a))
		return (1);
	//if (a.num_meals > 0)
	//{
	//	if (pthread_create(&a.eating, NULL, check_num_meals, &a))
	//		return (error(5));
	//	if (pthread_detach(a.eating))
	//		return (error(4));
	//}
	//	check_num_meals(&a, -1, 0);	
	if (start_thread(&a))
		return (1);
	sem_close(a.forks);
	sem_close(a.out);
	free(a.philo);
	return (0);
}
