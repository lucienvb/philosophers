#include "include/philo.h"

// Need to fix that all the threads use the same mutexes and not copies of the same mutexes like now
void	*thread_routine(void *tmp)
{
    size_t			i;
    size_t			*arg;
    t_philo			*phil;
//	pthread_mutex_t	mutex;

//	pthread_mutex_init(&mutex, NULL);
    phil = (t_philo *) tmp;

    arg = &phil->arg[phil->i];
    i = 0;
	printf("Philosopher %d is thinking\n", *(int *) arg);
	if (pthread_mutex_lock(phil->mutex) == 0)
	{
		printf("Philosopher %d is eating\n", *(int *) arg);
		usleep(phil->time_to_eat * ten_power_six);
		pthread_mutex_unlock(phil->mutex);
	}
//    while (i < (size_t) phil->time_to_die)
//    {
//        printf("Philosopher %d is thinking\n", *(int *) arg);
//        usleep(250000);
//        i++;
//    }
    if (i == (size_t) phil->time_to_die)
        return("philosopher has died\n");
//	pthread_mutex_destroy(&mutex);
    return ("philosopher is thinking\n");
}
