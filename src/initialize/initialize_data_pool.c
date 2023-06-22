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

#include "philo.h"

// this function checks if a string is only containing integers
static bool	str_is_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

// this function checks if all giving parameters of argv except
// for argv[0] are integers
static bool	is_all_num(int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < (size_t) argc)
	{
		if (str_is_num(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

// this function saves the giving parameters in the (public) shared
// struct: data_pool
// afterwards, some variables of data_pool are initialized
bool	initialize_data_pool(int argc, char **argv, t_public *data_pool)
{
	if (is_all_num(argc, argv) == false)
		return (false);
	if (ft_atol_with_overflow(argv[1],
			&data_pool->number_of_philosophers) == false
		|| data_pool->number_of_philosophers == 0
		|| data_pool->number_of_philosophers > 2047)
		return (false);
	if (ft_atol_with_overflow(argv[2], &data_pool->time_to_die) == false)
		return (false);
	if (ft_atol_with_overflow(argv[3], &data_pool->time_to_eat) == false)
		return (false);
	if (ft_atol_with_overflow(argv[4], &data_pool->time_to_sleep) == false)
		return (false);
	if (argc == 6)
	{
		if (ft_atol_with_overflow(argv[5],
				&data_pool->number_of_times_each_philosopher_must_eat) == false)
			return (false);
	}
	data_pool->thread_counter = 0;
	data_pool->reached_meal_count = 0;
	data_pool->stop = false;
	return (true);
}
