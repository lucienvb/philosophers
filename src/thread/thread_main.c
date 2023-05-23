//#include "philo.h"
#include "../../include/philo.h"

int thread_main(t_shared *shared_resources)
{
    char			**thread_result;
    pthread_t 		*thread;
    size_t			*arg;

    thread_result = NULL;
    arg = NULL;
	initialize(&shared_resources->phil, &thread_result, &thread, arg);
    thread_create(shared_resources, thread);
   	// maybe free stuff when pthread_join fails (free everything that's previously malloc)
	if (thread_join(shared_resources->phil.number_of_philosophers, thread, thread_result) == false)
		return (0);
    thread_print_result(shared_resources->phil.number_of_philosophers, thread_result);
	return (0);
}
