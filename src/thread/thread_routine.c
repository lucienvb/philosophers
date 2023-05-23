#include "include/philo.h"

// Need to fix that all the threads use the same mutexes and not copies of the same mutexes like now
void	*thread_routine(void *tmp)
{
    size_t			i;
    size_t			*arg;
    t_philo			*phil;

    phil = (t_philo *) tmp;

    arg = &phil->arg[phil->i];
    i = 0;
	printf("Philosopher %d is thinking\n", *(int *) arg);
//	if (pthread_mutex_lock(phil->mutex[phil->i]) == 0 && pthread_mutex_lock(phil->mutex[phil->i - 1]) == 0)
	if (pthread_mutex_lock(phil->mutex[phil->i]) == 0)
	{
		printf("Philosopher %d is eating\n", *(int *) arg);
		usleep(phil->time_to_eat * ten_power_six);
		pthread_mutex_unlock(phil->mutex[phil->i]);
//		pthread_mutex_unlock(phil->mutex[phil->i - 1]);
	}
    if (i == (size_t) phil->time_to_die)
        return("philosopher has died\n");
    return ("philosopher is thinking\n");
}
