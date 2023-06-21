/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_arguments.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:09:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/20 13:09:46 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	str_is_num(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool is_all_num(int argc, char **argv)
{
    size_t i;

    i = 1;
    while (i < (size_t) argc)
	{
		if (str_is_num(argv[i]) == false)
			return (false);
		i++;
    }
	return (true);
}

bool prepare_arguments(int argc, char **argv, t_public *data_pool)
{
	bool	valid_number;

	if (is_all_num(argc, argv) == false)
		return (false);
	valid_number = true;
	valid_number = ft_atol_with_overflow(argv[1], &data_pool->number_of_philosophers);
	if (valid_number == false || data_pool->number_of_philosophers == 0
			|| data_pool->number_of_philosophers > 2047)
		return (false);
	valid_number = ft_atol_with_overflow(argv[2], &data_pool->time_to_die);
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[3], &data_pool->time_to_eat);
	if (valid_number == false)
		return (false);
	valid_number = ft_atol_with_overflow(argv[4], &data_pool->time_to_sleep);
	if (valid_number == false)
		return (false);
	if (argc == 6)
	{
		valid_number = ft_atol_with_overflow(argv[5], &data_pool->number_of_times_each_philosopher_must_eat);
		if (valid_number == false)
			return (false);
	}
	data_pool->thread_counter = 0;
	data_pool->reached_meal_count = 0;
	return (valid_number);
}
