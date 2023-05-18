//#include <philo.h>
#include "../include/philo.h"

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

int main(int argc, char **argv)
{
	long	number_of_philosophers;
	bool	valid_number;

	if (argc != 5)
		return (0);
	valid_number = ft_atol_with_overflow(argv[1], &number_of_philosophers);
	if (valid_number == false)
		return (0);
	thread_main(number_of_philosophers);
	return (0);
}