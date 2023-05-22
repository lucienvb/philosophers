#include "include/philo.h"

void	*thread_routine(void *tmp)
{
    size_t	i;
    size_t  *arg;
    t_philo *phil;

    phil = (t_philo *) tmp;

    arg = &phil->arg[phil->i];
    i = 0;
    while (i < (size_t) phil->time_to_die)
    {
        printf("Philosopher %d is thinking\n", *(int *) arg);
        usleep(250000);
        i++;
    }
    if (i == (size_t) phil->time_to_die)
        return("philosopher has died\n");
    return ("philosopher is thinking\n");
}
