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
# include <limits.h>
# include <stddef.h>
# include <time.h>
# include <sys/time.h>



// DEFINE
# define THOUSAND 1000
# define ZERO 0

// ENUM
typedef enum e_mutexindex
{
	START,
	PRINT,
	TIME,
	STOP,
}	t_mutexindex;

// TIME
typedef struct s_time
{
    int64_t start;
    int64_t time_since_last_meal;
    long 	time_to_die;
}           t_time;

// PUBLIC STRUCT
typedef struct s_public
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int 			thread_counter;
	bool			stop;
	pthread_mutex_t *mutex;
	long 			i;
}					t_public;

// PHILO STRUCT (PRIVATE)
typedef struct s_philo
{
	size_t  		id;
	t_public		*data_pool;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
    bool            dead;
}					t_philo;

// FUNCTIONS
bool	philo(char *str);

// INITIALIZE
bool    initialize(t_public *data_pool, t_philo *phil, char ***thread_result, pthread_t **thread);

// MUTEX
bool	mutex_initialize(pthread_mutex_t **mutex, size_t number_of_philosophers);
bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers);

// THREAD
void    thread_print_result(size_t number_of_philosopherss, char **thread_result);
int 	thread_main(t_public *data_pool);
bool	thread_join(size_t number_of_philosopherss, pthread_t *thread, char **thread_result);
void	thread_create(t_philo *philos, pthread_t *thread, long number_of_philosophers);
void	*thread_routine(void *tmp);
int		thread_main_new(t_public *data_pool);

// TIME
int64_t	time_difference_ms(int64_t end, int64_t start);
int64_t	time_of_day_ms(void);
void	time_sleep_ms(int64_t time_to_sleep);
bool	time_sleep_and_validate(int64_t time_to_sleep, t_philo *phil);

// UTILS
bool	ft_atol_with_overflow(const char *str, long *result);
void	*ft_memcpy(void *dst, void *src, size_t n);
bool 	prepare_arguments(char **argv, t_public *data_pool);
bool	parser(int argc);
bool	stop_now(t_philo *phil);

#endif
