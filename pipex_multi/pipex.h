
#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

extern char	**environ;

char	**ft_getenv(char *s);
char	**ft_join_pc(char **path, char *cmd);
void	ft_clean(char **t);
void	ft_clean3d(char ***t);
char	***ft_cmds_t(int argc, char **argv);
char	***ft_cmdpath_t(char ***cmds_t);
size_t	ft_strlen(const char *s);
char	**ft_msplit(char const *s, char c);
char	*ft_cjoin(char const *s1, char const *s2);
int		ft_len3(char ***s);
void	pipex(int *fd, char ***cmds_t, char ***cmdpath_t);


# endif
