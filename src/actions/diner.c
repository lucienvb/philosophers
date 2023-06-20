#include <philo.h>

static bool dine(t_philo *phil, t_time *time, pthread_mutex_t *first, pthread_mutex_t *second)
{
    if (pthread_mutex_lock(first) == 0 && pthread_mutex_lock(second) == 0)
    {
//        if (check_if_alive(phil, time->time_since_last_meal, time->time_to_die) == false)
        if (check_if_alive(phil, time) == false)
        {
            pthread_mutex_unlock(second);
            pthread_mutex_unlock(first);
            return (false);
        }
        print(&phil->data_pool->mutex[PRINT], phil, "has taken a fork", time->start);
		print(&phil->data_pool->mutex[PRINT], phil, "is eating", time->start);
		if (time_sleep_and_validate(phil->data_pool->time_to_eat, phil) == false) {
			return (false);
		}
		if (pthread_mutex_lock(&phil->data_pool->mutex[MEAL]) == 0)
		{
			phil->meal_count++;
			if (phil->meal_count == phil->number_of_times_each_philosopher_must_eat)
				phil->data_pool->reached_meal_count++;
			pthread_mutex_unlock(&phil->data_pool->mutex[MEAL]);
		}
		pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
    }
    return (true);
}

bool diner(t_philo *phil, t_time *time)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    if (phil->id % 2 == 0)
    {
        first = phil->left;
        second = phil->right;
    }
    else
    {
        first = phil->right;
        second = phil->left;
    }
    return (dine(phil, time, first, second));
}
