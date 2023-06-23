/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   meal_status.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:56:14 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:56:15 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// this function can be used to set the shared stop boolean to true when the
// set parameter (boolean) is set to true
// in this case, the function stops
// this function can also be used to increase the meal_count of a thread
// after diner by setting the parameter add boolean to true
// the function is also checking if every thread has finished his meals
// if so, the stop boolean is set to true (which let the program stop)
void	meal_status(t_philo *phil, bool add, bool set)
{
	long	number_of_philosophers;

	pthread_mutex_lock(&phil->data_pool->mutex[STOP]);
	if (set)
	{
		phil->data_pool->stop = true;
		pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
		return ;
	}
	if (add)
	{
		phil->meal_count++;
		if (phil->meal_count == phil->number_of_times_each_philosopher_must_eat)
			phil->data_pool->reached_meal_count++;
	}
	ft_memcpy(&number_of_philosophers, &phil->data_pool->number_of_philosophers,
		sizeof(long));
	if (phil->data_pool->reached_meal_count == number_of_philosophers)
		phil->data_pool->stop = true;
	pthread_mutex_unlock(&phil->data_pool->mutex[STOP]);
}
