#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_philo
{
    int eat;
    int die;
    int sleep;
    struct s_all *all;   
} t_philo;

typedef struct s_all
{
    int time_eat;
    int time_die;
    int time_sleep;    
    int num_philo;
    int num_forks;
    int num_meals;
    pthread_t *thread;
    t_philo *philo;
}   t_all;

int main(int ac, char **av);
int		ft_atoi(const char *str);
#endif
