#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>

# define MAX_PHI 256

# define ON_TABLE	0
# define TAKEN		1

# define PLACE  0
# define DEATH  1
# define PRINT	2
# define ALLFKS	3

typedef struct	data
{
	bool			frk[MAX_PHI];
	pthread_mutex_t	mutex[4];
	int				philo_place_nbr;
	bool			one_is_dead;
	int				tot_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
}	t_data;

typedef struct	philo_data
{
	int		n;
	bool	have2frks;
	long	clock_eat;
	long	clock;
	int		meals;
}	t_phidata;

void	ft_check_args(int argc, char **argv);
int		ft_init_data(t_data *gdata, char **argv);
int		ft_dining_philosophers(void *data);

#endif
