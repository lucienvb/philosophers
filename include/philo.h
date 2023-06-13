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

// PUBLIC STRUCT
typedef struct s_public
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int 			thread_counter;
	size_t          test;
	pthread_mutex_t *mutex;
	pthread_mutex_t	start_mutex;
	// long i is temporary
	long 			i;
}					t_public;

// PHILO STRUCT (PRIVATE)
//typedef struct s_philo
//{
//	pthread_mutex_t		*start_mutex;
//	long				i;
//} 						t_philo;
typedef struct s_philo
{
	size_t			*id;
	size_t  		i;
	t_public		*data_pool;
}					t_philo;

// FUNCTIONS
bool	philo(char *str);

// INITIALIZE
bool    initialize(t_public *data_pool, t_philo *phil, char ***thread_result, pthread_t **thread);

// MUTEX
bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers);

// THREAD
void    thread_print_result(size_t number_of_philosopherss, char **thread_result);
int 	thread_main(t_public *data_pool);
bool	thread_join(size_t number_of_philosopherss, pthread_t *thread, char **thread_result);
void	thread_create(t_philo *philos, pthread_t *thread, long number_of_philosophers);
void	*thread_routine(void *tmp);
int		thread_main_new(t_public *data_pool);

// UTILS
bool	ft_atol_with_overflow(const char *str, long *result);
void	*ft_memcpy(void *dst, void *src, size_t n);
bool 	prepare_arguments(char **argv, t_public *data_pool);
bool	parser(int argc);

#endif
