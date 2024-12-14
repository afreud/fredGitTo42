/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:17:50 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 13:31:28 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (!(s) || !(*f))
		return (NULL);
	str = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[j] = (*f)(i, s[i]);
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
