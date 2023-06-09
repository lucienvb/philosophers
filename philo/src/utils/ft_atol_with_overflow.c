/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol_with_overflow.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:55:45 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:55:46 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static bool	iterate_and_create(const char *str, size_t i, long *result)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + str[i] - '0';
		if (*result < 0 && *result != INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_atol_with_overflow(const char *str, long *result)
{
	size_t	i;
	long	sign;
	size_t	len;

	sign = 1;
	i = 0;
	*result = 0;
	if (!str)
		return (1);
	len = ft_strlen(str);
	if (len == 1 && str[0] == ZERO)
	{
		*result = 0;
		return (true);
	}
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		return (false);
	}
	if (!iterate_and_create(str, i, result))
		return (false);
	*result *= sign;
	return (true);
}
