#include <philo.h>

void thread_print_result(size_t number_of_philosopherss, char **thread_result)
{
    size_t  i;

    i = 0;
    while (i < number_of_philosopherss)
    {
        printf("result thread %zu: %s\n", i + 1, thread_result[i]);
        i++;
    }
}