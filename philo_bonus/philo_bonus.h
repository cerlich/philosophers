/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:04:18 by cerlich           #+#    #+#             */
/*   Updated: 2021/08/06 20:37:48 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_philo
{
	int				eat;
	long			time_die;
	int				num;
	int				num_meals;
	int				status;
	long			start_time;
	pid_t			pid;
	pthread_t		monitor;
	struct s_all	*all;
}					t_philo;

typedef struct s_all
{
	long		time_eat;
	long		time_die;
	long		time_sleep;
	int			num_philo;
	int			num_forks;
	int			num_meals;
	int			end_sim;
	long		start_time;
	sem_t		*out;
	sem_t		*forks;
	sem_t		*meals;
	pthread_t	eating;
	t_philo		*philo;
}				t_all;

int		main(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	get_time(void);
int		parse_args(int ac, char **av, t_all *all);
int		error(int id);
void	ft_usleep(long time);
int		start_thread(t_all *a);

#endif
