#include <philo.h>

bool	thread_join(size_t number_of_philosopherss, pthread_t *thread, char **thread_result)
{
    size_t	i;

    i = 0;
    while (i < number_of_philosopherss)
    {
        // maybe free stuff when pthread_join fails (free everything that's previously malloc)
        if (pthread_join(thread[i], (void **) &thread_result[i]) != 0)
            return (false);
        i++;
    }
    return (true);
}
