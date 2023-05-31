#ifndef PHILO_H
#define PHILO_H

// INCLUDE
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <assert.h>
#include <limits.h>
#include <stddef.h>

// DEFINE
# define THOUSAND 1000

// It is possible to make a shared pool readonly with only constant variable, then data races are not possible
// DATA POOL STRUCT
//typdef struct s_data_pool
//{
//	pthread_mutex_t **mutex;
//	bool			should_stop;
//	bool 			is_dead;
//}					t_data_pool;

// PHILO STRUCT
typedef struct s_philo
{
	size_t			*arg;
    long			number_of_philosophers;
	long			time_to_die;
    long			time_to_eat;
    long			time_to_sleep;
//	pthread_mutex_t	*left_fork;
//	pthread_mutex_t *right_fork;
	pthread_mutex_t *mutex;
    size_t  		i;
}			t_philo;

// FUNCTIONS
bool	philo(char *str);
int 	thread_main(t_philo *phil);


// INITIALIZE
bool    initialize(t_philo *phil, char ***thread_result, pthread_t **thread, size_t *arg);

// MUTEX
bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers);

// THREAD
void    thread_print_result(size_t number_of_threads, char **thread_result);
bool	thread_join(size_t number_of_threads, pthread_t *thread, char **thread_result);
void	thread_create(t_philo *phil, pthread_t *thread, pthread_mutex_t **mutex);
void	*thread_routine(void *tmp);

// UTILS
bool	ft_atol_with_overflow(const char *str, long *result);
void	*ft_memcpy(void *dst, void *src, size_t n);
//bool 	prepare_arguments(char **argv, t_philo *phil);
bool	parser(int argc);

#endif
