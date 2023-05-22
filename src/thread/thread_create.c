#include "include/philo.h"

void	thread_create(size_t number_of_threads, t_philo *phil, pthread_t *thread)
{
    t_philo *thread_phil;
    size_t i;

    i = 0;
    while (i < number_of_threads)
    {
        thread_phil = malloc(sizeof(t_philo));
        if (!thread_phil)
            return ;
        memcpy(thread_phil, phil, sizeof(t_philo));
        // maybe free stuff when pthread_create fails (free everything that's previously malloc)
        if (pthread_create(&thread[i], NULL, thread_routine, (void *) thread_phil) != 0)
            return ;
        phil->i++;
        i++;
    }
}