#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	clist
{
	int				nb;
	int				index;
	int				pk0;
	int				push_cost;
	int				rank;
	bool			send;
	struct clist	*target;
	struct clist	*next;
	struct clist	*prev;
}t_clist;

void	ft_sa(t_clist **list_a, int p);
void	ft_sb(t_clist **list_b, int p);
void	ft_ss(t_clist **list_a, t_clist **list_b);
void	ft_ra(t_clist **list_a);
void	ft_rb(t_clist **list_b);
void	ft_rr(t_clist **list_a, t_clist **list_b);
void	ft_rra(t_clist **list_a);
void	ft_rrb(t_clist **list_b);
void	ft_rrr(t_clist **list_a, t_clist **list_b);
void	ft_pa(t_clist **list_b, t_clist **list_a);
void	ft_pb(t_clist **list_a, t_clist **list_b);
char	**ft_split(char const *s, char c);
char	**ft_clean2(char **strs);
char	***ft_clean3(char ***s)	;
int		ft_len2(char **s);
int		ft_len3(char ***s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);
int		ft_abs(int n);
void	ft_clr_lst(t_clist **lst);
int		ft_lstlen(t_clist *lst);
bool	ft_islower(t_clist *a, t_clist *tg_lst);
t_clist	*ft_wbigger(t_clist *lst);
bool	ft_args_ok(char **args);
char	**ft_creatab(char **av);
t_clist	*ft_creat_list(int argc, char **argv);
void	ft_index(t_clist *lst);
void	ft_index2(t_clist *lst_a, t_clist *lst_b);
void	ft_ranking(t_clist *lst);
void	ft_set_bool(t_clist *lst, int max_rank);
t_clist *ft_tosend(t_clist *lst, t_clist *tgt_lst);
void	ft_sort_small(t_clist **list_a, t_clist **list_b);
bool	ft_sort_one(t_clist **lst, t_clist **tgt_lst);
void	ft_sort_all(t_clist **lst_a, t_clist **lst_b);
void	ft_diff_ro(int idx_a, int idx_b, t_clist **lst_a, t_clist **lst_b);
void	ft_diff_rro(int rpk0_a, int rpk0_b, t_clist **lst_a, t_clist **lst_b);
void	ft_diff(int pk0_a, int pk0_b, t_clist **lst_a, t_clist **lst_b);
bool	ft_isa_ordered(t_clist *lst);
void	ft_reorder_a(t_clist **lst_a, t_clist **lst_b);
void	ft_reorder_b(t_clist **lst_b);

#endif
