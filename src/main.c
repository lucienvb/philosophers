#include <philo.h>

int main(int argc, char **argv)
{
	t_public	data_pool;

    (void)argv;
	if (parser(argc) == false)
		return (0);
    if (prepare_arguments(argc, argv, &data_pool) == false)
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
	thread_main_new(&data_pool);
	return (0);
}
