#include "include/philo.h"

void thread_print_result(size_t number_of_threads, char **thread_result)
{
    size_t  i;

    i = 0;
    while (i < number_of_threads)
    {
        printf("result thread %zu: %s\n", i + 1, thread_result[i]);
        i++;
    }
}