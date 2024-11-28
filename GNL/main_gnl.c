/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:46:07 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/28 11:13:55 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("file3", O_RDONLY);
	if (fd < 0)
		return (42);
	i = 1;
	while (line = get_next_line(fd), line)
	{
		printf("[%d]%s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
