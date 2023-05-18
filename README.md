# philosophers

The Dining Philosopher Problem states that N philosophers seated around a circular table with a large bowl of spaghetti and one fork between each pair of philosopher. Each philosopher is doing one of the three things: eating, sleeping, thinking. While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping. I should state that philosophers aren’t aware of other philosophers status.
The goal here is to create a program that simulate the 3 states of philosophers and log print any change of status as follow:

- timestamp_in_ms N philo has taken a fork
- timestamp_in_ms N philo is eating
- timestamp_in_ms N philo is sleeping
- timestamp_in_ms N philo is thinking
- timestamp_in_ms N philo died

## Installation
The program is compiled into a `philo` executable using `make all`

The program takes the following arguments:

>./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

1. number_of_philosophers: The number of philosophers and also the number of forks.
2. time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
3. time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
4. time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
5. number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
