/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:04:54 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 15:57:47 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;
	t_list	*current;

	buffer = *lst;
	while (buffer && del)
	{
		current = buffer->next;
		(*del)(buffer->content);
		free(buffer);
		buffer = current;
	}
	*lst = NULL;
}
