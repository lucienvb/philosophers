/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleeping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:24:35 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:24:37 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// this function let a thread sleep for a period of time_to_sleep
// before it does two checks:
// 1) if the thread is alive
// 2) if the thread needs to stop (because another thread has died)
bool	sleeping(t_philo *phil, t_time *time)
{
	if (check_if_alive(phil, time) == false)
		return (false);
	if (print(&phil->data_pool->mutex[PRINT], phil, "is sleeping",
			time->start) == false)
		return (false);
	if (time_sleep_and_validate(time->time_to_sleep, phil) == false)
		return (false);
	return (true);
}
