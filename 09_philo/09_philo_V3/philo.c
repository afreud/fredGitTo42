
#include "philo.h"

void	ft_take_place(t_data *gdata, int phi[3], long clock[2])
{
	pthread_mutex_lock(&gdata->mutex[PLACE]);
	if (gdata->tot_philo == 3)
	{
		phi[N] = gdata->philo_place_nbr;
		if (phi[N])
			clock[TIME] += gdata->eat_time;
		if (phi[N] == 2)
			clock[TIME] += gdata->eat_time;
		gdata->philo_place_nbr += 1;
	}
	else
	{
		if (gdata->philo_place_nbr >= (gdata->tot_philo))
			gdata->philo_place_nbr = 1;
		phi[N] = gdata->philo_place_nbr;
		if (phi[N] % 2)
			clock[TIME] += gdata->eat_time;
		gdata->philo_place_nbr += 2;
	}
	pthread_mutex_unlock(&gdata->mutex[PLACE]);
	usleep(gdata->eat_time * 10);	/////////////////////////////////
}

void	ft_add_time(t_data *gdata, int phi[3], long clock[2])
{
	if (gdata->tot_philo == 3 && phi[MEALS])
	{
		if ((2 * gdata->eat_time) >= gdata->sleep_time)
			clock[TIME] += 2 * gdata->eat_time;
		else
			clock[TIME] += gdata->sleep_time;
	}
	else if (phi[MEALS])
	{
		if (gdata->eat_time >= gdata->sleep_time)
			clock[TIME] += gdata->eat_time;
		else
			clock[TIME] += gdata->sleep_time;
	}
}

bool	ft_take_frk(t_data *gdata, int phi[3], long clock[2])
{
	pthread_mutex_lock(&gdata->mutex[ALLFKS]);
	if (gdata->frk[phi[N]] == ON_TABLE
		&& gdata->frk[(phi[N] + 1) % gdata->tot_philo] == ON_TABLE)
	{
		gdata->frk[(phi[N] + 1) % gdata->tot_philo] = TAKEN;
		gdata->frk[phi[N]] = TAKEN;
		phi[HAV2FKS] = 1;
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d has taken a fork\n", clock[TIME], (phi[N] + 1));
		printf("%ld %d has taken a fork\n", clock[TIME], (phi[N] + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
	else
	{
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		return (1);
	}
	return (0);
}

void	ft_eat_and_sleep(t_data *gdata, int phi[3], long clock[2])
{
	if (phi[HAV2FKS])
	{
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is eating\n", clock[TIME], (phi[N] + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
		usleep(gdata->eat_time * 10);	////////////////////////
		clock[EAT_TIME] = clock[TIME];
		clock[TIME] += gdata->eat_time;
		phi[MEALS] += 1;
		pthread_mutex_lock(&gdata->mutex[ALLFKS]);
		gdata->frk[phi[N]] = ON_TABLE;
		gdata->frk[(phi[N] + 1) % gdata->tot_philo] = ON_TABLE;
		phi[HAV2FKS] = 0;
		pthread_mutex_unlock(&gdata->mutex[ALLFKS]);
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is sleeping\n", clock[TIME], (phi[N] + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
		usleep(gdata->sleep_time * 10);	////////////////////////
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is thinking\n",
			(clock[TIME] + gdata->sleep_time), (phi[N] + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
}

int	ft_check_death(t_data *gdata, int phi[3], long clock[2])
{
	if (clock[TIME] - clock[EAT_TIME] > gdata->death_time)
	{
		pthread_mutex_lock(&gdata->mutex[DEATH]);
		gdata->one_is_dead = 1;
		pthread_mutex_unlock(&gdata->mutex[DEATH]);
		usleep((gdata->eat_time) * 10);	/////////////////////////////
		pthread_mutex_lock(&gdata->mutex[PRINT]);
		printf("%ld %d is dead\n", clock[EAT_TIME]
			+ gdata->death_time, (phi[N] + 1));
		pthread_mutex_unlock(&gdata->mutex[PRINT]);
	}
	pthread_mutex_lock(&gdata->mutex[DEATH]);
	if (gdata->one_is_dead
		|| (gdata->meals_nbr && phi[MEALS] == gdata->meals_nbr))
	{
		pthread_mutex_unlock(&gdata->mutex[DEATH]);
		return (1);
	}
	pthread_mutex_unlock(&gdata->mutex[DEATH]);
	return (0);
}

int	ft_dining_philosophers(void *data)
{
	t_data	*gdata;
	int		phi[3];
	long	clock[2];

	memset(&phi, 0, sizeof(phi));
	memset(&clock, 0, sizeof(clock));
	gdata = (t_data *)data;
	ft_take_place(gdata, phi, clock);
	while (!gdata->one_is_dead
		&& (!gdata->meals_nbr || (phi[MEALS] < gdata->meals_nbr)))
	{
		ft_add_time(gdata, phi, clock);
		if (ft_check_death(gdata, phi, clock))
			return (0);
		while (ft_take_frk(gdata, phi, clock))
			;
		ft_eat_and_sleep(gdata, phi, clock);
	}
	return (0);
}
