/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                '                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:47:08 by frdurand          #+#    #+#             */
/*   Updated: 2024/12/03 11:01:49 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

 static char	*ft_limiter(char *line, char *limiter)
{
	char *limiter_cp;

	limiter_cp = ft_gljoin(limiter, "\n");
	if (ft_strcmp(line, limiter_cp) == 0)
	{
		free(line);
		line = NULL;
		close(0);
	}
	free(limiter_cp);
	limiter_cp = NULL;
	return (line);
}

static ssize_t	ft_read_file(int fd, char *buff)
{
	ssize_t	count;
	int		i;

	i = BUFFER_SIZE;
	while (i >= 0)
		buff[i--] = '\0';
	count = read(fd, buff, BUFFER_SIZE);
	return (count);
}

static char	*ft_tostash(char *stash, char *buff, int count)
{
	char	*temp;

	if (count < 0 || (!count && !stash) || (!count && !*stash))
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_gllen(stash, '\0') + 1));
	if (temp)
	{
		ft_glcp(temp, stash, '\0');
		if (stash)
			free(stash);
		stash = ft_gljoin(temp, buff);
		free(temp);
		temp = NULL;
	}
	return (stash);
}

static char	*ft_toline(char *stash, char *limiter)
{
	char	end[2];
	char	*line;
	char	*temp;

	end[0] = ft_eol(stash);
	end[1] = '\0';
	line = NULL;
	temp = malloc(sizeof(char) * (ft_gllen(stash, ft_eol(stash)) + 2));
	if (temp)
	{
		temp[0] = '\0';
		ft_glcp(temp, stash, ft_eol(stash));
		line = ft_gljoin(temp, end);
		free(temp);
		temp = NULL;
	}
	line = ft_limiter(line, limiter);
	if (!line)
	{
		free(stash);
		stash = NULL;
	}
	else
		ft_cutstash(stash);
	return (line);
}

char	*get_next_line(int fd, char *limiter)
{
	ssize_t		count;
	int			t;
	char		*buff;
	static char	*stash = NULL;
	char		*line;

	t = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (t)
	{
		count = ft_read_file(fd, buff);
		stash = ft_tostash(stash, buff, count);
		if (!stash || ft_eol(stash) == '\n' || (!(ft_eol(stash)) && !count))
			t = 0;
	}
	free(buff);
	buff = NULL;
	if (stash)
		line = ft_toline(stash, limiter);
	return (line);
}