/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_alive.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:55:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:55:36 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// TIME MUTEX
// this function checks if the time till the next meal of a thread has passed
// (what means that he dies)
// if so, it checks if another thread hasn't died first
// if that isn't the case the thread prints it has died and
// sets the shared stop boolean to true
bool	check_if_alive(t_philo *phil, t_time *time)
{
	pthread_mutex_lock(&phil->data_pool->mutex[TIME]);
	if (time_difference_ms(time_of_day_ms(), time->time_since_last_meal)
		>= (int64_t) time->time_to_die)
	{
		if (stop_now(phil) == true)
		{
			pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
			return (false);
		}
		meal_status(phil, 0, 1);
		printf("%ld %ld died\n", (long) time_difference_ms(time_of_day_ms(),
				time->start), phil->id);
		pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
		return (false);
	}
	meal_status(phil, 0, 0);
	pthread_mutex_unlock(&phil->data_pool->mutex[TIME]);
	return (true);
}
