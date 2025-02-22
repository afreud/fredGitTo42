/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:53:57 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/20 14:31:46 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	g_trigger = 0;

static int	ft_ctlpid(int pid)
{
	int	err_sav;

	if (kill(pid, 0) == -1 || pid == -1)
	{
		err_sav = errno;
		if (err_sav == EPERM)
		{
			write(2, "Bad permissions for this process\n", 33);
			exit(err_sav);
		}
		else if (err_sav == ESRCH)
		{
			write(2, "Process does not exist\n", 23);
			exit(err_sav);
		}
		else
		{
			write(2, "Wrong PID\n", 10);
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
		g_trigger = 1;
	if (sig == SIGUSR2)
		write(1, "Message received\n", 17);
}

static void	ft_err_pid(void)
{
	write(2, "Wrong PID\n", 10);
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
			write(2, "Problem kill\n", 13);
			exit(err_sav);
		}
		while (!g_trigger)
			usleep(1);
		g_trigger = 0;
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
		ft_sendchar(pid, '\n');
		return (0);
	}
	write(2, "Error arguments\n", 16);
	return (1);
}
