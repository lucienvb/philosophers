#include <philo.h>

bool prepare_arguments(char **argv, t_philo *phil)
{
	bool	valid_number;

	valid_number = true;
	valid_number = ft_atol_with_overflow(argv[1], &phil->number_of_philosophers);
	phil->number_of_philosophers++;
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[2], &phil->time_to_die);
	if (valid_number == false || phil->time_to_die < 1)
		return (false);
	valid_number = ft_atol_with_overflow(argv[3], &phil->time_to_eat);
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[4], &phil->time_to_sleep);
	if (valid_number == false)
		return (false);

	// printing the parameters
	printf("\nnumber of philosophers: %zu\n", phil->number_of_philosophers);
	printf("time to die: %zu\n", phil->time_to_die);
	printf("time to eat: %zu\n", phil->time_to_eat);
	printf("time to sleep: %zu\n\n", phil->time_to_sleep);
	return (valid_number);
}
