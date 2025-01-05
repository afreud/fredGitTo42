#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	clist
{
	int				nb;
	struct clist	*next;
	struct clist	*prev;
}t_clist;

int		ft_atoi(const char *nptr);
void	ft_ra(t_clist **list_a);
void	ft_rb(t_clist **list_b);
void	ft_rr(t_clist **list_a, t_clist **list_b);
void	ft_rra(t_clist **list_a);
void	ft_rrr(t_clist **list_a, t_clist **list_b);
void	ft_pb(t_clist **list_a, t_clist **list_b);
void	ft_pa(t_clist **list_a, t_clist **list_b);
void	ft_sb(t_clist **list_b);
void	ft_sa(t_clist **list_a);
t_clist	*ft_creat_list(int argc, char **argv);
t_clist	*ft_clnew(int n);
void	ft_clr_lst(t_clist **lst);
void	ft_sort_small(int argc, t_clist **list_a);


#endif
