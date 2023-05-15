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


// FUNCTIONS
bool	philo(char *str);
int 	thread_main(size_t number_of_philosophers);
bool	ft_atol_with_overflow(const char *str, long *result);

#endif
