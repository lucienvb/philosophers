/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   diner.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:24:28 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:24:29 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	unlock(pthread_mutex_t *first, pthread_mutex_t *second)
{
	if (second != NULL)
		pthread_mutex_unlock(second);
	if (first != NULL)
		pthread_mutex_unlock(first);
}

static bool	dead(t_philo *phil, t_time *time, pthread_mutex_t *first,
					pthread_mutex_t *second)
{
	if (check_if_alive(phil, time) == false)
	{
		if (second != NULL)
			pthread_mutex_unlock(second);
		if (first != NULL)
			pthread_mutex_unlock(first);
		return (true);
	}
	return (false);
}

// in this function a thread tries to lock two forks
// when it succeeds it checks whether it should stop or start with eating
// when false it's going to eat
// when the eating isn't interrupted his time_since_last_meal is resetting and
// the meal_status is updated
bool	diner(t_philo *phil, t_time *time, pthread_mutex_t *first,
			pthread_mutex_t *second)
{
	if (pthread_mutex_lock(first) == 0)
		print(&phil->data_pool->mutex[PRINT], phil, "has taken a fork",
			time->start);
	if (dead(phil, time, first, NULL) == true)
		return (false);
	if (pthread_mutex_lock(second) == 0)
	{
		print(&phil->data_pool->mutex[PRINT], phil, "has taken a fork",
			time->start);
		if (dead(phil, time, first, second) == true)
			return (false);
		print(&phil->data_pool->mutex[PRINT], phil, "is eating", time->start);
		time->time_since_last_meal = time_of_day_ms();
		if (time_sleep_and_validate(time->time_to_eat, phil) == false)
		{
			unlock(first, second);
			return (false);
		}
		meal_status(phil, 1, 0);
		unlock(first, second);
	}
	return (true);
}
