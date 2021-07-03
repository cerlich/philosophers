#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mute;

typedef struct s_philo
{
	int				eat;
	long			time_die;
	int				num;
	int				num_meals;
	t_mute			*left_fork;
	t_mute			*right_fork;
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
	pthread_t	*thread_philo;
	pthread_t	*thread_death;
	pthread_t	*thread_meals;
	t_philo		*philo;
	t_mute		*fork;
	t_mute		*out;
}				t_all;

int		main(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	get_time(void);
void	init_args(t_all *all);
int		parse_args(int ac, char **av, t_all *all);
int		error(int id);
void	ft_usleep(long time);
void	destroy_mutex(t_all *all);
int		malloc_thread(t_all *a);

#endif
