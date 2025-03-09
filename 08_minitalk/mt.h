/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:50:31 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/20 13:59:06 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# define SIZE 958

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
#include <stdbool.h>

char	*ft_realloc(char *s, int index);
int		ft_args_ok(char *arg);
int		ft_atoi(const char *nptr);
int		ft_nblen(int n);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
