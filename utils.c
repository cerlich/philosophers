#include "philo.h"

void			ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int error(int id)
{
	if (id == 0)
		printf("Main error: wrong numbers of args\n");
	if (id == 1)
		printf("Main error: invalid args\n");
	if (id == 2)
		printf("Malloc error\n");
	if (id  == 3)
		printf("Main error: can't create thread\n");
	if (id  == 4)
		printf("Main error: can't detach thread\n");
	exit (1);
}

long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * n);
}