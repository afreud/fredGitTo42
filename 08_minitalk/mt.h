#ifndef MT_H
# define MT_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <limits.h>

void	ft_eot(char *s, int *index, int pid);
char	*ft_realloc(char *s, int index);
int		ft_args_ok(char *arg);
int		ft_atoi(const char *nptr);
int		ft_nblen(int n);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

# endif
