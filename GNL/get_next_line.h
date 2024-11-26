#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
ssize_t	ft_gllen(char *str, char c);
char	ft_eol(char *s);
void	ft_glcp(char *des, char *src, char c);
char	*ft_gljoin(char *s1, char *s2);
void	ft_cutstash(char *stash);

#endif
