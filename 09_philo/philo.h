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
# define TAKEN 1
# define ON_TABLE 0

# define PLACE 0
# define CLOCK 1
# define DEATH 2
# define ONE_EAT 3
# define ONE_SLEEP 4

typedef struct	data
{
	int				philo_place_nbr;
	pthread_mutex_t	frk_mutex[MAX_PHI];
	bool			frk[MAX_PHI];
	pthread_mutex_t	mutex[5];
	bool			have2frks[MAX_PHI];
	bool			have_eat[MAX_PHI];
	long			clock;
	bool			one_is_dead;
	bool			one_is_eating;
	bool			one_is_sleeping;
	int				tot_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				meals_nbr;
}	t_data;


void	ft_check_args(int argc, char **argv);
int		ft_init_data(t_data *pdata, char **argv);
int		ft_dining_philosophers(void *data);
void	ft_check_death(t_data *pdata, int p_num, int clock_eat);
void	ft_take_place(t_data *pdata, int *p_num, int *clock_eat);

#endif
