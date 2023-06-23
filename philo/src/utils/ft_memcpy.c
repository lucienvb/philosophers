/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:55:55 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/06/22 14:55:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
