/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_mutex.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:29:31 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:29:32 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// this functions allocates a number of mutexes for a count of
// number_of_philosophers plus 4 (for e_mutex_index: START, PRINT,
// TIME, STOP)
// afterwards, all these mutexes are being initialized
bool	initialize_mutex(pthread_mutex_t **mutex, size_t number_of_philosophers)
{
	size_t	i;

	*mutex = malloc(number_of_philosophers * sizeof(pthread_mutex_t));
	if (!*mutex)
		return (false);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&(*mutex)[i], NULL) != 0)
			return (free(*mutex), false);
		i++;
	}
	return (true);
}
