/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_threads.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:29:45 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:29:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// this function allocates threads for an amount of number_of_philosophers
bool	initialize_threads(pthread_t **thread, size_t number_of_philosophers)
{
	*thread = malloc(number_of_philosophers * sizeof(pthread_t));
	if (!*thread)
		return (false);
	return (true);
}
