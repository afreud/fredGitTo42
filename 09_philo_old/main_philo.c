/*
PTHREAD_MUTEX_DEFAULT
PTHREAD_MUTEX_ERRORCHECK
PTHREAD_MUTEX_NORMAL
PTHREAD_MUTEX_INITIALIZER
PTHREAD_MUTEX_RECURSIVE
*/

#include "philo.h"

int main(int argc, char **argv)
{
	pthread_t	philo[256];
	t_data		pdata;
	int			i;
	int			err;

	err = 0;
	i = 0;
	memset(&pdata, 0, sizeof(pdata));
	ft_check_args(argc, argv);
	err = ft_init_data(&pdata, argv);
	while (!err && i < pdata.tot_philo)
		err = pthread_create(&philo[i++], NULL, (void *)ft_dining_philosophers, &pdata);
	i = 0;
	while (!err && i < pdata.tot_philo)
		err = pthread_join(philo[i++], NULL);
	i = 0;
	while (!err && i < pdata.tot_philo)
		err = pthread_mutex_destroy(&(pdata.frk_mutex[i++]));
	i = 0;
	while (!err && i < 5)
		err = pthread_mutex_destroy(&(pdata.mutex[i++]));
	if (err)
		write(2, "Problem mutex", 13);
	return (err);
}
