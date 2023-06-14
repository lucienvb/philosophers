#include <philo.h>

bool prepare_arguments(char **argv, t_public *data_pool)
{
	bool	valid_number;

	valid_number = true;
	valid_number = ft_atol_with_overflow(argv[1], &data_pool->number_of_philosophers);
//	data_pool->number_of_philosophers++;
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[2], &data_pool->time_to_die);
	if (valid_number == false || data_pool->time_to_die < 1)
		return (false);
	valid_number = ft_atol_with_overflow(argv[3], &data_pool->time_to_eat);
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[4], &data_pool->time_to_sleep);
	if (valid_number == false)
		return (false);

	data_pool->thread_counter = 0;
	// printing the parameters
	printf("\nnumber of philosophers: %zu\n", data_pool->number_of_philosophers);
	printf("time to die: %zu\n", data_pool->time_to_die);
	printf("time to eat: %zu\n", data_pool->time_to_eat);
	printf("time to sleep: %zu\n\n", data_pool->time_to_sleep);
	return (valid_number);
}
