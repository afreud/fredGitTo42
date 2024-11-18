/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:02:32 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 17:16:15 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	lst = &buffer;
	(*lst)->next = new;
}
