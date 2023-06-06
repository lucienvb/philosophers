#include <philo.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return (dst);
}
