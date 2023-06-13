#include <philo.h>

int main(int argc, char **argv)
{
	t_public	data_pool;

    (void)argv;
	if (parser(argc) == false)
		return (0);
    if (prepare_arguments(argv, &data_pool) == false)
	{
		printf("invalid input\n");
		return (0);
	}
	thread_main_new(&data_pool);
	return (0);
}
