
#include "philo.h"

void	ft_take_place(t_data *gdata, t_phidata *phi) // n, clock[TIME]
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
	usleep(gdata->eat_time * 10);
//	if (gdata->tot_philo == 3)
//		usleep(gdata->eat_time * 10);
}

void	ft_add_time(t_data *gdata, t_phidata *phi) // meals, clock[TIME]
{
	if (gdata->tot_philo == 3 && phi->meals)
	{
		if ((2 * gdata->eat_time) >= gdata->sleep_time)
			phi->clock += 2 * gdata->eat_time;
		else
			phi->clock += gdata->sleep_time;
	}
	else if (phi->meals)
	{
		if (gdata->eat_time >= gdata->sleep_time)
			phi->clock += gdata->eat_time;
		else
			phi->clock += gdata->sleep_time;
	}
}

bool	ft_take_frk(t_data *gdata, t_phidata *phi) // n, have2frks, clock[TIME]
{
	pthread_mutex_lock(&gdata->mutex[ALLFKS]);
	if (gdata->frk[phi->n] == ON_TABLE && gdata->frk[(phi->n + 1) % gdata->tot_philo] == ON_TABLE)
	{
		gdata->frk[(phi->n + 1) % gdata->tot_philo] = TAKEN;
		gdata->frk[phi->n] = TAKEN;
		phi->have2frks = 1;
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d has taken a fork\n", phi->clock, (phi->n + 1));
		printf("%ld %d has taken a fork\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
	else
	{
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		return (1);
	}
	return (0);
}

void	ft_eat_and_sleep(t_data *gdata, t_phidata *phi) // n, clock[TIME], clock[EAT_TIME], have2frks, meals
{
	if (phi->have2frks)
	{
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is eating\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);

		usleep(gdata->eat_time * 10);
//		if (gdata->tot_philo == 3)
//			usleep(gdata->eat_time * 10);

		phi->clock_eat = phi->clock;
		phi->clock += gdata->eat_time;
		phi->meals += 1;
		pthread_mutex_lock(&gdata->mutex[ALLFKS]);
		gdata->frk[phi->n] = ON_TABLE;
		gdata->frk[(phi->n + 1) % gdata->tot_philo] = ON_TABLE;
		phi->have2frks = 0;
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is sleeping\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);

		usleep(gdata->sleep_time * 10);
//		if (gdata->tot_philo == 3)
//			usleep(gdata->sleep_time * 10);

		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is thinking\n", (phi->clock + gdata->sleep_time), (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
}

int	ft_check_death(t_data *gdata, t_phidata *phi) // n, clock[TIME], clock[EAT_TIME], meals
{
	if (phi->clock - phi->clock_eat > gdata->death_time)
	{
		pthread_mutex_lock(&gdata->mutex[DEATH]);
		gdata->one_is_dead = 1;
		pthread_mutex_unlock(&gdata->mutex[DEATH]);

		//usleep(gdata->sleep_time * 10);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is dead\n", phi->clock, (phi->n + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
	pthread_mutex_lock(&gdata->mutex[DEATH]);
	if (gdata->one_is_dead || phi->meals == gdata->meals_nbr)
	{
		pthread_mutex_unlock(&gdata->mutex[DEATH]);
		return (1);
	}
	pthread_mutex_unlock(&gdata->mutex[DEATH]);
	return (0);
}

int	ft_dining_philosophers(void *data) // int n, long clock[2] {define TIME 0, define EAT_TIME 1}, bool have2frks, int meals
{
	t_data		*gdata;
	t_phidata	phi;
	
	memset(&phi, 0, sizeof(phi));
	gdata = (t_data *)data;
	ft_take_place(gdata, &phi);
	while (!gdata->one_is_dead && (!gdata->meals_nbr || (phi.meals < gdata->meals_nbr)))
	{
		ft_add_time(gdata, &phi);

		if (ft_check_death(gdata, &phi))
			return (0);

		while (ft_take_frk(gdata, &phi))
			;

		ft_eat_and_sleep(gdata, &phi);

	}
	return (0);
}
