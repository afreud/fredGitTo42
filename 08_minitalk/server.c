
#include "mt.h"
#include <stdio.h>

static void	ft_wrchar(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;
	static int				j;
	static char				*s = NULL;

	(void)context;
	if (!s)
	{
		s = malloc(sizeof(char) * 1024);
		if (!s)
			exit(EXIT_FAILURE);
		ft_bzero(s, sizeof(s));
	}
	if (sig == SIGINT || sig == SIGTERM)
		ft_eot(s, NULL, info->si_pid);
	if (sig == SIGUSR1)
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		s[j++] = c;
		c = 0;
		i = 0;
		if (s[j - 1] == '\n')
		{
			ft_eot(s, &j, info->si_pid);
			return ;
		}
		if (j == sizeof(s) - 1)
			s = ft_realloc(s, j);
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	int					pid;
	char				*s;
	struct sigaction	act;

	pid = getpid();
	s = ft_itoa(pid);
	if (!s)
		return (1);
	write(1, s, ft_nblen(pid));
	write(1, "\n", 1);
	free(s);
	s = NULL;
	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = ft_wrchar;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGTERM, &act, NULL);
		pause();
	}
	return (0);
}
