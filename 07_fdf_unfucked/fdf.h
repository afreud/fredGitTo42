
#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <limits.h>

#include <stdio.h>

#define ANGL 60
#define BUFFER_SIZE 50
#define WIN_X 720
#define WIN_Y 860

typedef struct	map
{
	int	width;
	int	height;
	int	**pts_3d;
	int	**pts_2d;
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
int		ft_abs(int n);
int		ft_width(char ***spts);
int		ft_height(int fd, char *path);
char	**ft_split(char const *s, char c);
char	***ft_spts(char *path);
int		**ft_2d_points(char ***spts, int **t3d);
int 	**ft_3d_points(char ***pts);
int		ft_atoi(const char *nptr);
void	ft_clrtab(int **tab);
void	ft_clrexit(char ****s, int fd);
char	***ft_clean3(char ***t);
void	ft_init(char *path, t_xdata *xdata);
int		ft_len2(char **s);
int		ft_len3(char ***s);
int	 	ft_no_event(t_xdata *xdata);
int		ft_key_input(int key, t_xdata *xdata);
int		ft_red_cross(t_xdata *xdata);
void	ft_pixels(t_xdata *xdata);
void	ft_mlxexit(t_xdata *xdata);
void	ft_draw_line(int *pt_start, int *pt_end, t_img *img);
void	ft_center(t_map *map);

#endif
