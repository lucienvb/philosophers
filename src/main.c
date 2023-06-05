#include <philo.h>

int main(int argc, char **argv)
{
	t_philo	phil;

	if (parser(argc) == false)
		return (0);
    if (prepare_arguments(argv, &phil) == false)
        return (0);
	thread_main(&phil);
	return (0);
}
