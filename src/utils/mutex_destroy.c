/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex_destroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:56:21 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:56:23 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	mutex_destroy(pthread_mutex_t *mutex, size_t number_of_philosophers)
{
	size_t	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_destroy(&mutex[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}
