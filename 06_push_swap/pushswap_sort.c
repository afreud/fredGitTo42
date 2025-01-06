#include "pushswap.h"

static void	ft_sort_nl(t_clist *tosend, t_clist **lst, t_clist **tgt_lst)
{
	int	i;

	i = tosend->pk0;
	while (i > 0)
	{
		ft_ra(lst);
		i--;
	}
	while (i < 0)
	{
		ft_rra(lst);
		i++;
	}
	ft_pb(lst, tgt_lst);
}

static void	ft_sort_pos(t_clist *tosend, t_clist **lst, t_clist **tgt_lst)
{
	int	i;
	int j;

	i = tosend->pk0;
	j = tosend->target->pk0;
	while (i && j)
	{
		ft_rr(lst, tgt_lst);
		i--;
		j--;
	}
	while (i)
	{
		ft_ra(lst);
		i--;
	}
	while (j)
	{
		ft_rb(tgt_lst);
		j--;
	}
	ft_pb(lst, tgt_lst);
}

static void	ft_sort_neg(t_clist *tosend, t_clist **lst, t_clist **tgt_lst)
{
	int	i;
	int j;

	i = tosend->pk0;
	j = tosend->target->pk0;
	while (i && j)
	{
		ft_rrr(lst, tgt_lst);
		i++;
		j++;
	}
	while (i)
	{
		ft_rra(lst);
		i++;
	}
	while (j)
	{
		ft_rrb(tgt_lst);
		j++;
	}
	ft_pb(lst, tgt_lst);
}

static void	ft_sort_dif(t_clist *tosend, t_clist **lst, t_clist **tgt_lst)
{
	t_clist	*a;
	t_clist *b;
	int		rpk0a;
	int		rpk0b;

	a = tosend;
	b = tosend->target;
	rpk0a = a->pk0 - ft_lstlen(a);
	rpk0b = b->pk0 - ft_lstlen(b);

		if ((a->pk0 >= b->index) || (b->pk0 >= a->index))
		{
			while ((a->index) && (b->index))
			{
				ft_rr(lst, tgt_lst);
				--(a->index);
				--(b->index);
			}
			while (a->index)
			{
				ft_ra(lst);
				--(a->index);
			}
			while (b->index)
			{
				ft_rb(tgt_lst);
				--(b->index);
			}
			ft_pb(lst, tgt_lst);
		}


		else if (a->pk0 < 0 && a->pk0 <= (b->pk0 - ft_lstlen(b)))
		{
			while ((a->pk0) && rpk0b)
			{
				ft_rrr(lst, tgt_lst);
				++(a->pk0);
				++rpk0b;
			}
			while (a->pk0)
			{
				ft_rra(lst);
				++(a->pk0);
			}
			ft_pb(lst, tgt_lst);
		}


		else if (b->pk0 < 0 && b->pk0 <= (a->pk0 - ft_lstlen(a)))
		{
			while ((b->pk0) && rpk0a)
			{
				ft_rrr(lst, tgt_lst);
				++(b->pk0);
				++rpk0a;
			}
			while (b->pk0)
			{
				ft_rrb(tgt_lst);
				++(b->pk0);
			}
			ft_pb(lst, tgt_lst);
		}


		else
		{
			if (a->pk0 > 0)
			{
				while (a->pk0)
				{
					ft_ra(lst);
					--(a->pk0);
				}
				while (b->pk0)
				{
					ft_rrb(tgt_lst);
					++(b->pk0);
				}
				ft_pb(lst, tgt_lst);
			}
			else
			{
				while (b->pk0)
				{
					ft_rb(tgt_lst);
					--(b->pk0);
				}
				while (a->pk0)
				{
					ft_rra(lst);
					++(a->pk0);
				}
				ft_pb(lst, tgt_lst);
			}
		}
}

void	ft_sort(t_clist **lst, t_clist **tgt_lst)
{
	t_clist	*tosend;

	tosend = ft_tosend(*lst, *tgt_lst);
	if (tosend->target == NULL)
		ft_sort_nl(tosend, lst, tgt_lst);
	else if (tosend->pk0 >= 0 && tosend->target->pk0 >= 0)
		ft_sort_pos(tosend, lst, tgt_lst);
	else if (tosend->pk0 <= 0 && tosend->target->pk0 <= 0)
		ft_sort_neg(tosend, lst, tgt_lst);
	else
		ft_sort_dif(tosend, lst, tgt_lst);
}
