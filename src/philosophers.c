//#include "philo.h"
#include "../include/philo.h"

bool	philo(char *str)
{
	if (write(STDOUT_FILENO, str, strlen(str)) != -1)
		return (true);
	return (false);
}
