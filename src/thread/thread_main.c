//#include "philo.h"
#include "../../include/philo.h"

int thread_main(t_philo *phil)
{
    char			**thread_result;
    pthread_t 		*thread;
    size_t			*arg;
	pthread_mutex_t	mutex;

    thread_result = NULL;
    arg = NULL;
	initialize(phil, &thread_result, &thread, arg);
	pthread_mutex_init(&mutex, NULL);
	thread_create(phil, thread, &mutex);
   	// maybe free stuff when pthread_join fails (free everything that's previously malloc)
	if (thread_join(phil->number_of_philosophers, thread, thread_result) == false)
		return (0);
    thread_print_result(phil->number_of_philosophers, thread_result);
	pthread_mutex_destroy(&mutex);
	return (0);
}
