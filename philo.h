#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_philo
{
    int eat;
    int die;
    int num_philo;
    int sleep;
    int num_times_to_eat;
    int num_forks;
    struct s_all *all;   
} t_philo;

typedef struct s_all
{
    pthread_t *thread;
    t_philo *philo;
}   t_all;

int main(int ac, char **av);
int		ft_atoi(const char *str);
#endif
