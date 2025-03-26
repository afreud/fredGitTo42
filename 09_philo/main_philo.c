
#include "philo.h"

int main(int argc, char **argv)
{
	pthread_t	philo[MAX_PHI];
	t_data		gdata;
	int			i;
	int			err;

	i = 0;
	memset(&gdata, 0, sizeof(gdata));
	ft_check_args(argc, argv);
	err = ft_init_data(&gdata, argv);
	while (!err && i < gdata.tot_philo)
	{
		err = pthread_create(&philo[i++], NULL, (void *)ft_dining_philosophers, &gdata);
		usleep(100);
	}
	i = 0;
	while (!err && i < gdata.tot_philo)
		err = pthread_join(philo[i++], NULL);
	i = 0;
	while (!err && i < gdata.tot_philo)
		err = pthread_mutex_destroy(&(gdata.frk_mutex[i++]));
	i = 0;
	while (!err && i < 4)
		err = pthread_mutex_destroy(&(gdata.mutex[i++]));
	if (err)
		write(2, "Problem mutex\n", 14);
	return (err);
}
