#include <philo.h>
//
//void	thread_create(t_philo *philos, pthread_t *thread, long number_of_philosophers)
//{
//	size_t	i;
//
//	i = 0;
//	while (i < (size_t) number_of_philosophers)
//    {
//		if (pthread_create(&thread[i], NULL, thread_routine, (void *) &philos[i]) != 0)
//		{
//			free(&philos[i]);
//			return ;
//		}
//		i++;
//    }
//
//    while (1) {
//        pthread_mutex_lock(&philos->data_pool->start_mutex);
//        if (i == (size_t) number_of_philosophers)
//        {
//            pthread_mutex_unlock(&philos->data_pool->start_mutex);
//            break;
//        }
//        pthread_mutex_unlock(&philos->data_pool->start_mutex);
//        usleep(100);
//    }
//
//    pthread_mutex_lock(&philos->data_pool->start_mutex);
//	pthread_mutex_unlock(&philos->data_pool->start_mutex);
//
//	for (int i = 0; i < number_of_philosophers; ++i) {
//		pthread_join(thread[i], NULL);
//	}
//
//	free(thread);
//	pthread_mutex_destroy(&philos->data_pool->start_mutex);
//
//}
// if a following thread fails, the program has to stop
