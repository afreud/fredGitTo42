/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:53:57 by frdurand          #+#    #+#             */
/*   Updated: 2025/03/06 11:09:32 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

bool	g_is_received = 0;

static int	ft_ctlpid(int pid)
{
	int	err_sav;

	if (kill(pid, 0) == -1 || pid == -1)
	{
		err_sav = errno;
		if (err_sav == EPERM)
		{
			(void)!write(2, "\nOperation not permitted\n", 25);
			exit(err_sav);
		}
		else if (err_sav == ESRCH)
		{
			(void)!write(2, "\nNo such process\n", 17);
			exit(err_sav);
		}
		else
		{
			(void)!write(2, "\nNot this PID please\n", 21);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_is_received = 1;
}

static void	ft_err_pid(void)
{
	(void)!write(2, "\nWrong PID\n", 11);
	exit(EXIT_FAILURE);
}

static void	ft_sendchar(int pid, unsigned char c)
{
	int	i;
	int	r;
	int	err_sav;

	i = 0;
	r = 0;
	while (pid && i < 8)
	{
		if (c & (0x01 << i))
			r = kill(pid, SIGUSR1);
		else
			r = kill(pid, SIGUSR2);
		if (r == -1)
		{
			err_sav = errno;
			(void)!write(2, "\nProblem kill\n", 14);
			exit(err_sav);
		}
		while (!g_is_received)
			usleep(1);
		g_is_received = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	act;

	pid = 0;
	i = 0;
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc == 3)
	{
		if (ft_args_ok(argv[1]))
			pid = ft_ctlpid(ft_atoi(argv[1]));
		else
			ft_err_pid();
		while (argv[2][i])
			ft_sendchar(pid, (unsigned char)argv[2][i++]);
		ft_sendchar(pid, '\0');
		return (0);
	}
	(void)!write(2, "\nError arguments\n", 17);
	return (1);
}
