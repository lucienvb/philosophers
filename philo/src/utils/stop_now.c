/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_now.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:58:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:58:37 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// STOP MUTEX
// this function checks whether the shared stop boolean is set to
// true or not
// if so, it returns true
bool	stop_now(t_philo *phil)
{
	pthread_mutex_lock(&phil->data_pool->mutex[STOP]);
	if (phil->data_pool->stop == true)
	{
		pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
		return (true);
	}
	pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
	return (false);
}
