/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:19:31 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:19:33 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_public	data_pool;
	long		number_of_philosophers;

	if (parser(argc) == false || initialize_data_pool(argc, argv, &data_pool)
		== false)
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
	ft_memcpy(&number_of_philosophers, &data_pool.number_of_philosophers,
		sizeof(long));
	return (thread_main(&data_pool, number_of_philosophers));
}
