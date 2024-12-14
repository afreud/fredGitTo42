/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:07:28 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:36:22 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_new;

	s_new = (struct s_list *)malloc(sizeof(struct s_list));
	if (s_new == NULL)
		return (NULL);
	s_new->content = content;
	s_new->next = NULL;
	return (s_new);
}
