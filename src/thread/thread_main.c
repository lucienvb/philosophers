//#include "philo.h"
#include "../include/philo.h"

int thread_main(t_philo *phil)
{
    char		**thread_result;
    pthread_t	*thread;
    size_t      *arg;

    thread_result = NULL;
    arg = NULL;
    initialize(phil, &thread_result, &thread, arg);
    thread_create(phil, thread);
   	// maybe free stuff when pthread_join fails (free everything that's previously malloc)
	if (thread_join(phil->number_of_philosophers, thread, thread_result) == false)
		return (0);
    thread_print_result(phil->number_of_philosophers, thread_result);
	return 0;
}
