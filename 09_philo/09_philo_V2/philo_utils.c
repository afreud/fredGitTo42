#include "philo.h"

int	ft_atoi_error(char **s)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		nb = 0;
		j = 0;
		while ( s[i][j] && (s[i][j] <= 32 || s[i][j] == '+'))
			j++;
		while (s[i][j])
		{
			if (s[i][j] < '0' || s[i][j] > '9')
				return (1);
			if ((s[i][j] - '0') > INT_MAX - (nb * 10))
			{
				return (1);
			}
			nb = ((nb * 10) + (s[i][j++] - '0'));
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] && nptr[i] <= 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		nbr = (nbr * 10) + (nptr[i++] - '0');
	return (nbr * sign);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("./philo <philo_nbr> <time_to_die> <time_to_eat> <time_to_sleep> [meals_nbr]");
		exit(EXIT_SUCCESS);
	}
	if (ft_atoi_error(&argv[1]))
	{
		printf("Error arguments\n");
		exit(EXIT_SUCCESS);
	}
	if (ft_atoi(argv[1]) > 256)
	{
		printf("Table too small for so much philosophers!\n");
		exit(EXIT_SUCCESS);
	}
	if (ft_atoi(argv[1]) < 2)
	{
		printf("A philosopher can't eat whith one fork!\n");
		exit(EXIT_SUCCESS);
	}
}

int	ft_init_data(t_data *gdata, char **argv)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (!err && i < 2)
		err = pthread_mutex_init(&(gdata->mutex[i++]), NULL);
	if (!err)
	{
		gdata->tot_philo = ft_atoi(argv[1]);
		gdata->death_time = ft_atoi(argv[2]);
		gdata->eat_time = ft_atoi(argv[3]);
		gdata->sleep_time = ft_atoi(argv[4]);
		if (argv[5])
			gdata->meals_nbr = ft_atoi(argv[5]) ;
	}
	return (err);
}
