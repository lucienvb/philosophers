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


// STRUCTURES
typedef struct s_philo
{
	size_t 	*arg;
	size_t 	time_to_die;
    size_t  i;
}			t_philo;

// FUNCTIONS
bool	philo(char *str);
int 	thread_main(size_t number_of_philosophers, size_t time_to_die);
bool	ft_atol_with_overflow(const char *str, long *result);

#endif
