/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:13:02 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/06 14:41:42 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80

# endif

char	***ft_allpaths_t(char ***cmds_t);
char	***ft_cmds_t(int argc, char **argv);
char	**ft_getenv(char *s);
char	**ft_msplit(char const *s, char c);
char	**ft_path_t(char ***cmds_t);
char	*ft_cjoin(char const *s1, char const *s2);
int		ft_len2(char **s);
int		ft_len3(char ***s);
size_t	ft_strlen(const char *s);
char	**ft_clean2(char **t);
char	***ft_clean3(char ***t);
void	ft_clean_close(int *fd, char ****cmds_t, char ***path_t);
int		pipex(int *fd, char ***cmds_t, char **path_t);
void	ft_open_files(int *fd, int argc, char **argv);
void	ft_closefd(int pipefd[512][2], int max);
void	ft_closefd2(int pipefd[512][2], int max, int fd[2]);
int		ft_strcmp(const char *s1, const char *s2);

#endif
