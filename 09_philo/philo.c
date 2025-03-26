
#include "philo.h"

void	ft_take_place(t_data *gdata, t_phidata *phi)
{
	pthread_mutex_lock(&gdata->mutex[PLACE]);
	if (gdata->tot_philo == 3)
	{
		phi->n = gdata->philo_place_nbr;
		if (phi->n)
			phi->clock += gdata->eat_time;
		if (phi->n == 2)
			phi->clock += gdata->eat_time;
		gdata->philo_place_nbr += 1;
	}
	else
	{
		if (gdata->philo_place_nbr >= (gdata->tot_philo))
			gdata->philo_place_nbr = 1;
		phi->n = gdata->philo_place_nbr;
		if (phi->n % 2)
			phi->clock += gdata->eat_time;
		gdata->philo_place_nbr += 2;
	}
	pthread_mutex_unlock(&gdata->mutex[PLACE]);
	usleep(1000);
}

bool	ft_take_frk(t_data *gdata, t_phidata *phi)
{
	pthread_mutex_lock(&gdata->mutex[ALLFKS]);
	if (gdata->frk[phi->n] == ON_TABLE && gdata->frk[(phi->n + 1) % gdata->tot_philo] == ON_TABLE)
	{
		pthread_mutex_lock(&gdata->frk_mutex[phi->n]);
		pthread_mutex_lock(&gdata->frk_mutex[(phi->n + 1) % gdata->tot_philo]);
	}
	else
	{
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		return (1);
	}
	phi->have2frks = 1;
	gdata->frk[(phi->n + 1) % gdata->tot_philo] = TAKEN;
	gdata->frk[phi->n] = TAKEN;
	pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
	pthread_mutex_lock(&gdata->mutex[PRINT]);
	printf("%ld %d has taken a fork\n", phi->clock, (phi->n + 1));
	printf("%ld %d has taken a fork\n", phi->clock, (phi->n + 1));
	pthread_mutex_unlock(&gdata->mutex[PRINT]);
	return (0);
}

void	ft_eat_and_sleep(t_data *gdata, t_phidata *phi)
{
	if (phi->have2frks)
	{
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is eating\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
		usleep(gdata->eat_time * 10);
		phi->clock_eat = phi->clock;
		phi->clock += gdata->eat_time;
		phi->meals += 1;
		pthread_mutex_lock(&gdata->mutex[ALLFKS]);
		gdata->frk[phi->n] = ON_TABLE;
		gdata->frk[(phi->n + 1) % gdata->tot_philo] = ON_TABLE;
		phi->have2frks = 0;
		pthread_mutex_unlock(&gdata->frk_mutex[phi->n]);
		pthread_mutex_unlock(&gdata->frk_mutex[(phi->n + 1) % gdata->tot_philo]);
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is sleeping\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
		phi->clock += gdata->sleep_time;
		usleep(gdata->sleep_time * 10);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is thinking\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
}

int	ft_check_death(t_data *gdata, t_phidata *phi)
{
	if (phi->clock - phi->clock_eat > gdata->death_time)
	{
		pthread_mutex_lock(&gdata->mutex[DEATH]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is dead\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
		gdata->one_is_dead = 1;
		pthread_mutex_unlock(&gdata->mutex[DEATH]);
	}
	if (gdata->one_is_dead || phi->meals == gdata->meals_nbr)
		return (1);
	return (0);
}

int	ft_dining_philosophers(void *data)
{
	t_data		*gdata;
	t_phidata	phi;
	
	memset(&phi, 0, sizeof(phi));
	phi.meals = 0;
	gdata = (t_data *)data;
	ft_take_place(gdata, &phi);
	while (!gdata->one_is_dead && (!gdata->meals_nbr || (phi.meals < gdata->meals_nbr)))
	{
		while (ft_take_frk(gdata, &phi))
			;
		ft_eat_and_sleep(gdata, &phi);

		if (ft_check_death(gdata, &phi))
			return (0);
	}
	return (0);
}
