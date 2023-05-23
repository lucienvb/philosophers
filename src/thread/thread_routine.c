#include "include/philo.h"

// Need to fix that all the threads use the same mutexes and not copies of the same mutexes like now
void	*thread_routine(void *tmp)
{
    size_t			i;
    size_t			*arg;
    t_shared		*shared_resources;
//	pthread_mutex_t	mutex;

	shared_resources = (t_shared *) tmp;
	pthread_mutex_init(&shared_resources->mutex, NULL);

    arg = &shared_resources->copy->arg[shared_resources->copy->i];
    i = 0;
	printf("Philosopher %d is thinking\n", *(int *) arg);
	if (pthread_mutex_lock(&shared_resources->mutex) == 0)
	{
		printf("Philosopher %d is eating\n", *(int *) arg);
		usleep(shared_resources->copy->time_to_eat * ten_power_six);
		pthread_mutex_unlock(&shared_resources->mutex);
	}
//    while (i < (size_t) phil->time_to_die)
//    {
//        printf("Philosopher %d is thinking\n", *(int *) arg);
//        usleep(250000);
//        i++;
//    }
    if (i == (size_t) shared_resources->copy->time_to_die)
        return("philosopher has died");
	pthread_mutex_destroy(&shared_resources->mutex);
    return ("philosopher is thinking");
}
