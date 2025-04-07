#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# define MAX_PHI 256

# define ON_TABLE	0
# define TAKEN		1

# define N			0
# define MEALS		1
# define HAV2FKS	2

# define TIME		0
# define EAT_TIME	1

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

void	ft_check_args(int argc, char **argv);
int		ft_init_data(t_data *gdata, char **argv);
int		ft_dining_philosophers(void *data);

#endif
