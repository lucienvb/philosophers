#include "include/philo.h"

// WARNING: memcpy still in there
void	thread_create(t_shared *shared_resources, pthread_t *thread)
{
	size_t i;

	i = 0;
    while (i < (size_t) shared_resources->phil.number_of_philosophers)
    {
		shared_resources->copy = malloc(sizeof(t_unshared));
        if (!shared_resources->copy)
            return ;
        ft_memcpy(shared_resources->copy, &shared_resources->phil, sizeof(t_unshared));
        // maybe free stuff when pthread_create fails (free everything that's previously malloc)
        if (pthread_create(&thread[i], NULL, thread_routine, (void *) shared_resources) != 0)
            return ;
        shared_resources->phil.i++;
        i++;
    }
}