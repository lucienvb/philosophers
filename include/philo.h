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
# define ZERO 0

// It is possible to make a shared pool readonly with only constant variable, then data races are not possible
// DATA POOL STRUCT
//typedef struct s_shared
//{
//	pthread_mutex_t dead;
//	bool			stop;
//}					t_shared;

// PHILO STRUCT
typedef struct s_philo
{
	size_t			*id;
    long			number_of_philosophers;
	long			time_to_die;
    long			time_to_eat;
    long			time_to_sleep;
	pthread_mutex_t *mutex;
//    t_shared		*data_pool;
    size_t  		i;
}			t_philo;

// FUNCTIONS
bool	philo(char *str);
int 	thread_main(t_philo *phil);


// INITIALIZE
bool    initialize(t_philo *phil, char ***thread_result, pthread_t **thread);

// MUTEX
bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers);

// THREAD
void    thread_print_result(size_t number_of_philosopherss, char **thread_result);
bool	thread_join(size_t number_of_philosopherss, pthread_t *thread, char **thread_result);
void	thread_create(t_philo *phil, pthread_t *thread, pthread_mutex_t **mutex);
void	*thread_routine(void *tmp);

// UTILS
bool	ft_atol_with_overflow(const char *str, long *result);
void	*ft_memcpy(void *dst, void *src, size_t n);
bool 	prepare_arguments(char **argv, t_philo *phil);
bool	parser(int argc);

#endif
