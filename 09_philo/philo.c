#include "philo.h"

void	ft_take_place(t_data *pdata, int *p_num, int *clock_eat)
{
	pthread_mutex_lock(&pdata->mutex[PLACE]);
	if (pdata->philo_place_nbr >= pdata->tot_philo)
		pdata->philo_place_nbr = 1;
	*p_num = (pdata->philo_place_nbr);
	pdata->philo_place_nbr += 2;
	*clock_eat = pdata->clock;
	pthread_mutex_unlock(&pdata->mutex[PLACE]);
}

bool	ft_take_frk(t_data *pdata, int p_num)
{
	
	if (pdata->frk[p_num] == ON_TABLE)
		pthread_mutex_lock(&pdata->frk_mutex[p_num]);
	else
		return (1);
	if (pdata->frk[p_num + 1] == ON_TABLE)
		pthread_mutex_lock(&pdata->frk_mutex[(p_num + 1) % pdata->tot_philo]);
	else
	{
		pthread_mutex_unlock(&pdata->frk_mutex[p_num]);
		return (1);
	}
	pdata->have2frks[p_num] = 1;
	pdata->frk[(p_num + 1) % pdata->tot_philo] = TAKEN;
	pdata->frk[p_num] = TAKEN;
	printf("%ld %d has taken a fork\n", pdata->clock, (p_num + 1));
	printf("%ld %d has taken a fork\n", pdata->clock, (p_num + 1));
	return (0);
}

void	ft_eat(t_data *pdata, int p_num)
{
	if (pdata->have2frks[p_num])
	{
		printf("%ld %d is eating\n", pdata->clock, (p_num + 1));
		pdata->have_eat[p_num] = 1;
		if (!pdata->one_is_eating)
		{
			pthread_mutex_lock(&pdata->mutex[ONE_EAT]);
			pdata->one_is_eating = 1;
			pthread_mutex_lock(&pdata->mutex[CLOCK]);
			pdata->clock += pdata->eat_time;
			pdata->one_is_eating = 0;
			pthread_mutex_unlock(&pdata->mutex[ONE_EAT]);
			pthread_mutex_unlock(&pdata->mutex[CLOCK]);
		}
	}
}

void	ft_put_frk(t_data *pdata, int p_num)
{
	if (pdata->have_eat[p_num])
	{
		pdata->frk[p_num] = ON_TABLE;
		pdata->frk[(p_num + 1) % pdata->tot_philo] = ON_TABLE;
		pdata->have2frks[p_num] = 0;
		pthread_mutex_unlock(&pdata->frk_mutex[p_num]);
		pthread_mutex_unlock(&pdata->frk_mutex[(p_num + 1) % pdata->tot_philo]);
	}
}

void	ft_sleep(t_data *pdata, int p_num)
{
	if (pdata->have_eat[p_num])
	{
		printf("%ld %d is sleeping\n", pdata->clock, (p_num + 1));
		pdata->have_eat[p_num] = 0;
		if (!pdata->one_is_sleeping)
		{
			pthread_mutex_lock(&pdata->mutex[ONE_SLEEP]);
			pdata->one_is_sleeping = 1;
			pthread_mutex_lock(&pdata->mutex[CLOCK]);
			pdata->clock += pdata->sleep_time;
			pdata->one_is_sleeping = 0;
			pthread_mutex_unlock(&pdata->mutex[ONE_SLEEP]);
			pthread_mutex_unlock(&pdata->mutex[CLOCK]);
		}
	}
}

void	ft_check_death(t_data *pdata, int p_num, int clock_eat)
{
	if ((clock_eat + pdata->death_time) > pdata->clock)
	{
		pthread_mutex_lock(&pdata->mutex[DEATH]);
		printf("%ld %d is dead\n", pdata->clock, (p_num + 1));
		pdata->one_is_dead = 1;
		pthread_mutex_unlock(&pdata->mutex[DEATH]);
	}
	if (pdata->one_is_dead || meals == pdata->meals_nbr)
		return (1);
	return (0);
}

int	ft_dining_philosophers(void *data)
{
	t_data	*pdata;
	int		p_num;
	int		clock_eat;
	int		meals;
	
	meals = 0;
	pdata = (t_data *)data;
	ft_take_place(pdata, &p_num, &clock_eat);
	while (!pdata->one_is_dead && (!pdata->meals_nbr || (meals < pdata->meals_nbr))
	{
		while (ft_take_frk(pdata, p_num))
		{
			if (ft_check_death(pdata, p_num, clock_eat))
			return (0);
		}
		ft_eat(pdata, p_num);
		meals++;
		clock_eat = pdata->clock;
		ft_put_frk(pdata, p_num);
		ft_sleep(pdata, p_num);
		printf("%ld %d is thinking\n", pdata->clock, (p_num + 1));
	}
	return (0);
}
