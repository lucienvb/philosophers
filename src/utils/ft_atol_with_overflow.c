#include <philo.h>

static size_t ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static bool	iterate_and_create(const char *str, size_t i,
								  size_t len, long *result)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == len - 1 && str[i] != '0')
			*result = (*result * 10) - 1 + (str[i] - '0');
		else
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
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!iterate_and_create(str, i, len, result))
		return (false);
	*result += 1;
	*result *= sign;
	return (true);
}
