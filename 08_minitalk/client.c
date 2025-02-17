
#include "mt.h"

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
	{
		return ;
	}
//	if (sig == SIGUSR2)
//		write(1, "Message recieved\n", 17);
}

static void	ft_sendchar(int pid, unsigned char c, struct sigaction *p_act)
{
	int	i;

	i = 0;
	while (pid && i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sigaction(SIGUSR1, p_act, NULL);
		pause();
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;
	int i;
	struct sigaction	act;

	pid = 0;
	i = 0;
	act.sa_handler = NULL;
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (argc == 3)
	{
		if (ft_args_ok(argv[1]))	
			pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_sendchar(pid, (unsigned char)argv[2][i], &act);
			i++;
		}
		ft_sendchar(pid, '\n', &act);
//		sigaction(SIGUSR2, &act, NULL);
//		pause();
		return (0);
	}
	write(1, "Error\n", 6);
	return (1);
}
