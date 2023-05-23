#ifndef PHILO_H
#define PHILO_H

// INCLUDE
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

// DEFINE
# define ten_power_six 1000000

// STRUCTURES
typedef struct s_philo
{
	size_t			*arg;
    long			number_of_philosophers;
	long			time_to_die;
    long			time_to_eat;
    long			time_to_sleep;
	pthread_mutex_t	*mutex;
    size_t  i;
}			t_philo;

// FUNCTIONS
bool	philo(char *str);
int 	thread_main(t_philo *phil);
bool	ft_atol_with_overflow(const char *str, long *result);

// INITIALIZE
bool    initialize(t_philo *phil, char ***thread_result, pthread_t **thread, size_t *arg);

// THREAD
void    thread_print_result(size_t number_of_threads, char **thread_result);
bool	thread_join(size_t number_of_threads, pthread_t *thread, char **thread_result);
void	thread_create(t_philo *phil, pthread_t *thread, pthread_mutex_t *mutex);
void	*thread_routine(void *tmp);

#endif
