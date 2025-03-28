
#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define BUFFER_SIZE 10000
#define WIN_X 720
#define WIN_Y 860

typedef struct	map
{
	int		width;
	int		height;
	long	**pts_3d;
	long	**pts_2d;
	char	*name;
}		t_map;

typedef struct image
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}			t_img;

typedef struct	xdata
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_map	map;
}			t_xdata;

char	*get_next_line(int fd);
ssize_t	ft_gllen(char *str, char c);
char	ft_eol(char *s);
void	ft_glcp(char *des, char *src, char c);
char	*ft_gljoin(char *s1, char *s2);
void	ft_cutstash(char *stash);

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_abs(int n);
bool	ft_atoi_error(char *s);
int		ft_width(char ***spts);
int		ft_height(int fd, char *path);
void	ft_chek_name(char *s, t_map *map);
char	***ft_spts(char *path, int i, t_xdata *xdata);
long	**ft_2d_points(char ***spts, long **t3d);
long	**ft_3d_points(char ***pts);
int		ft_len2(char **s);
int		ft_len3(char ***s);
void	ft_clrtab(long **tab);
char	***ft_clean3(char ***t);
void	ft_init(char *path, t_xdata *xdata);
int	 	ft_no_event(t_xdata *xdata);
int		ft_key_input(int key, t_xdata *xdata);
void	ft_center(t_map *map);
int		ft_colo(int z);
void	ft_pix2win(t_xdata *xdata);
void	ft_clrexit(char ****s, int fd, char *line, t_xdata *xdata);
void	ft_mlxexit(t_xdata *xdata, int err, char ***s);
int		ft_exit(t_xdata *xdata);

#endif
