#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define lock pthread_mutex_lock
# define unlock pthread_mutex_unlock

typedef pthread_mutex_t	t_mute;

typedef struct s_philo
{
    int eat;
    long int time_die;
    int num;
    //int num_meals;
    t_mute *left_fork;
    t_mute *right_fork;
    struct s_all *all;   
} t_philo;

typedef struct s_all
{
    long int time_eat;
    long int time_die;
    long int time_sleep;    
    int num_philo;
    int num_forks;
    int num_meals;
    int end_sim;
    pthread_t *thread_philo;
    pthread_t *thread_death;
    pthread_t *thread_meals;
    t_philo *philo;
    t_mute *fork;
}   t_all;

int main(int ac, char **av);
int		ft_atoi(const char *str);
long    get_time(void);
void init_args(t_all *all);
int parse_args(int ac, char **av, t_all *all);
int error(int id);
void			ft_usleep(long int time_in_ms);
void destroy_mutex(t_all *all);

#endif
