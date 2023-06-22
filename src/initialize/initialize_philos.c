#include <philo.h>

// this function initializes the (private) philos struct
void	initialize_philos(t_philo *philos, size_t i, t_public *data_pool, long number_of_philosophers)
{
	philos->id = i;
	philos->dead = false;
	philos->left = &data_pool->mutex[STOP + i + 1];
	philos->meal_count = 0;
	ft_memcpy(&philos->number_of_times_each_philosopher_must_eat,
			  &data_pool->number_of_times_each_philosopher_must_eat, sizeof(long));
	if ((STOP + i) == STOP)
		philos->right = &data_pool->mutex[STOP + number_of_philosophers];
	else
		philos->right = &data_pool->mutex[STOP + i];
	philos->data_pool = data_pool;
}
