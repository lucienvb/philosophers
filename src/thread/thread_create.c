#include "include/philo.h"

// WARNING: memcpy still in there
void	thread_create(t_philo *phil, pthread_t *thread, pthread_mutex_t *mutex)
{
    t_philo *thread_phil;
    size_t i;

    i = 0;
    while (i < (size_t) phil->number_of_philosophers)
    {
        thread_phil = malloc(sizeof(t_philo));
        if (!thread_phil)
            return ;
        memcpy(thread_phil, phil, sizeof(t_philo));
		thread_phil->mutex = mutex;
        // maybe free stuff when pthread_create fails (free everything that's previously malloc)
        if (pthread_create(&thread[i], NULL, thread_routine, (void *) thread_phil) != 0)
            return ;
        phil->i++;
        i++;
    }
}