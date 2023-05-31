#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool	philo(char *str)
{
	if (write(STDOUT_FILENO, str, strlen(str)) == -1)
		return (false);
	return (true);
}

//int	main(void)
//{
//	bool	ret;
//
//	ret = false;
//	ret = philo("hallo\n");
//	if (ret)
//		write(STDOUT_FILENO, "true\n", 5);
//	return(0);
//}