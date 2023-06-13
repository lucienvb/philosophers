#include <philo.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (NULL);
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
