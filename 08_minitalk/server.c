/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:56:05 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/20 14:06:50 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_eot(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	(void)!write(1, "\n\n-----Bye!-----\n", 17);
	exit(EXIT_SUCCESS);
}

static void	ft_err_kill(char **line, int err)
{
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	(void)!write(2, "Error kill\n", 11);
	exit(err);
}

static void	ft_putline(char *line, int *j, int pid)
{
	(void)!write(1, line, *j);
	(void)!write(1, "\n", 1);
	ft_bzero(line, *j);
	*j = 0;
	if (kill(pid, SIGUSR2) == -1)
		ft_err_kill(&line, errno);
}

static void	ft_wrchar(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				it_bit;
	static int				j;
	static char				*line = NULL;

	(void)context;
	line = ft_realloc(line, j);
	if (!line)
		exit(EXIT_FAILURE);
	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT)
		ft_eot(&line);
	if (sig == SIGUSR1)
		c |= (0x01 << it_bit);
	it_bit++;
	if (it_bit == 8)
	{
		line[j++] = c;
		c = '\0';
		it_bit = 0;
		if (line[j - 1] == '\0')
			ft_putline(line, &j, info->si_pid);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_err_kill(&line, errno);
}

int	main(void)
{
	int					pid;
	char				*s;
	struct sigaction	act;

	pid = getpid();
	s = ft_itoa(pid);
	if (!s)
		return (1);
	(void)!write(1, "--- Pid: ", 9);
	(void)!write(1, s, ft_nblen(pid));
	(void)!write(1, " ---\n\n", 6);
	free(s);
	s = NULL;
	act.sa_sigaction = ft_wrchar;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	while (1)
		pause();
	return (0);
}
