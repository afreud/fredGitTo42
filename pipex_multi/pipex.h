
#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

extern char	**environ;

char	***ft_allpaths_t(char ***cmds_t);
char	***ft_cmds_t(int argc, char **argv);
char	**ft_getenv(char *s);
char	**ft_msplit(char const *s, char c);
char	**ft_path_t(char ***cmds_t);
char	*ft_cjoin(char const *s1, char const *s2);
int		ft_len2(char **s);
int		ft_len3(char ***s);
size_t	ft_strlen(const char *s);
void	ft_clean2(char **t);
void	ft_clean3(char ***t);
void	pipex(int *fd, char ***cmds_t, char **path_t);


# endif
