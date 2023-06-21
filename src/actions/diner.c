#include <philo.h>

// in this function a thread tries to lock two forks
// when it succeeds it executes a validating whether it should stop or start with eating
// when false it's going to eat
// when the eating isn't interrupted his time_since_last_meal is resetting and
// the meal_status is updated
static bool dine(t_philo *phil, t_time *time, pthread_mutex_t *first, pthread_mutex_t *second)
{
    if (pthread_mutex_lock(first) == 0 && pthread_mutex_lock(second) == 0)
    {
        if (check_if_alive(phil, time) == false)
        {
            pthread_mutex_unlock(second);
            pthread_mutex_unlock(first);
            return (false);
        }
        print(&phil->data_pool->mutex[PRINT], phil, "has taken a fork", time->start);
		print(&phil->data_pool->mutex[PRINT], phil, "is eating", time->start);
		if (time_sleep_and_validate(phil->data_pool->time_to_eat, phil) == false)
		{
			pthread_mutex_unlock(second);
			pthread_mutex_unlock(first);
			return (false);
		}
        time->time_since_last_meal = time_of_day_ms();
		meal_status(phil, 1);
		pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
    }
    return (true);
}

// this function realizes that:
// - every thread with an even id number tries to pick first there left fork, then their right one
// - every thread odd id number tries to pick first there right fork, then their left one
// (this improves the functionality of picking up the forks (mutexes))
// afterwards, the dine function is called and, it's return value is returned
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
