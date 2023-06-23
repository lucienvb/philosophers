/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:56:40 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:56:41 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// PRINT MUTEX
// this function prints a given message
// first it checks if another philosopher has died
// if so, it returns false
bool	print(pthread_mutex_t *print, t_philo *phil, char *message,
			int64_t start)
{
	pthread_mutex_lock(print);
	if (stop_now(phil) == true)
	{
		pthread_mutex_unlock(print);
		return (false);
	}
	printf("%ld ", (long) time_difference_ms(time_of_day_ms(), start));
	printf("%ld", phil->id);
	printf(" %s\n", message);
	pthread_mutex_unlock(print);
	return (true);
}
