/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_usleep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:56:04 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:56:06 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// this function returns the time of day in milliseconds
int64_t	time_of_day_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// this function returns the difference between to given
// integers
int64_t	time_difference_ms(int64_t end, int64_t start)
{
	return (end - start);
}

// this function can be used to sleep an amount of milliseconds
// every 500 microseconds it checks the time
void	time_sleep_ms(int64_t time_to_sleep)
{
	const int64_t	start = time_of_day_ms();

	while (1)
	{
		if (time_difference_ms(time_of_day_ms(), start) >= time_to_sleep)
			break ;
		usleep(500);
	}
}

// this function can be used to sleep an amount of milliseconds
// every 500 microseconds it checks the time and if all philosophers
// are still alive, if not; it returns false
bool	time_sleep_and_validate(int64_t time_to_sleep, t_philo *phil)
{
	const int64_t	start = time_of_day_ms();

	while (1)
	{
		if (time_difference_ms(time_of_day_ms(), start) >= time_to_sleep)
			break ;
		if (stop_now(phil) == true)
			return (false);
		usleep(500);
	}
	return (true);
}
