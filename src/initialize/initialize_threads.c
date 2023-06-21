#include <philo.h>

bool	initialize_thread(pthread_t **thread, size_t number_of_philosophers)
{
    *thread = malloc(number_of_philosophers * sizeof(pthread_t));
    if (!*thread)
        return (false);
    return (true);
}
