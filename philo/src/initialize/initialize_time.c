/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_time.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:29:55 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:29:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	initialize_time(t_time *time, t_philo *phil)
{
	ft_memcpy(&time->time_to_die, &phil->data_pool->time_to_die, sizeof(long));
	ft_memcpy(&time->time_to_eat, &phil->data_pool->time_to_eat, sizeof(long));
	ft_memcpy(&time->time_to_sleep, &phil->data_pool->time_to_sleep,
		sizeof(long));
}
