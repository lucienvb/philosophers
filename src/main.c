//#include <philo.h>
#include "include/philo.h"

//int	main(void)
//{
//	bool	ret;
//
//	ret = false;
//	ret = philo("hallo\n");
//	if (ret)
//		write(STDOUT_FILENO, "true\n", 5);
//	return(0);
//}

static bool prepare_arguments(char **argv, t_philo *phil)
{
    bool	valid_number;

    valid_number = true;
    valid_number = ft_atol_with_overflow(argv[1], &phil->number_of_philosophers);
    if (valid_number == false)
        return (false);
    valid_number = ft_atol_with_overflow(argv[2], &phil->time_to_die);
    if (valid_number == false)
        return (false);
    valid_number = ft_atol_with_overflow(argv[3], &phil->time_to_eat);
    if (valid_number == false)
        return (false);
    valid_number = ft_atol_with_overflow(argv[4], &phil->time_to_sleep);
    if (valid_number == false)
        return (false);
    return (valid_number);
}

int main(int argc, char **argv)
{
	t_philo phil;

	if (argc != 5)
		return (0);
    if (prepare_arguments(argv, &phil) == false)
        return (0);
	thread_main(&phil);
	return (0);
}