#include <philo.h>

int main(int argc, char **argv)
{
	t_public	data_pool;
	long 		number_of_philosophers;

	if (parser(argc) == false || prepare_arguments(argc, argv, &data_pool) == false)
	{
		printf("invalid input\n");
		return (0);
	}
	if (data_pool.number_of_philosophers == 1)
	{
		time_sleep_ms(data_pool.time_to_die);
		printf("%ld 1 died\n", (long) data_pool.time_to_die);
		return (0);
	}
	ft_memcpy(&number_of_philosophers, &data_pool.number_of_philosophers, sizeof(long));
	thread_main_new(&data_pool, number_of_philosophers);
	return (0);
}
