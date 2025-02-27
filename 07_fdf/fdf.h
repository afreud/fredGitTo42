
#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include <stdio.h>

#define ANGL 60
#define BUFFER_SIZE 50
#define WIN_X 1920
#define WIN_Y 1080

typedef struct	data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_xdata;

typedef struct image
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

char	*get_next_line(int fd);
ssize_t	ft_gllen(char *str, char c);
char	ft_eol(char *s);
void	ft_glcp(char *des, char *src, char c);
char	*ft_gljoin(char *s1, char *s2);
void	ft_cutstash(char *stash);
char	**ft_split(char const *s, char c);
char	***ft_init_pts(char *path);
int 	**ft_2d_points(char ***pts);
int 	**ft_3d_points(char ***pts);
int		ft_atoi(const char *nptr);
void	ft_clrtab(int **tab);
void	ft_clrexit(char ****s, int fd);
char	***ft_clean3(char ***t);

#endif
