/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:07:01 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/13 18:01:23 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buffer;
	void	*tmp;

	new = NULL;
	buffer = NULL;
	while (lst && del && f)
	{
		tmp = f(lst->content);
		if (tmp)
			buffer = ft_lstnew(tmp);
		if (!buffer || !tmp)
		{
			del(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, buffer);
		lst = lst->next;
	}
	return (new);
}
