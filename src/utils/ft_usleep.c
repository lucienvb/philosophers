#include <philo.h>

int64_t	time_of_day_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int64_t	time_difference_ms(int64_t end, int64_t start)
{
	return (end - start);
}

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

bool	time_sleep_and_validate(int64_t time_to_sleep, t_philo *phil)
{
    const int64_t	start = time_of_day_ms();

//    (void)phil;
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
