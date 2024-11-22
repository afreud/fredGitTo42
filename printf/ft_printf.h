/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:02:36 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/22 13:29:19 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
ssize_t	ft_putadr(void *adr);
ssize_t	ft_putchar(int c);
ssize_t	ft_puthex(unsigned int exa, char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putunbr(unsigned int unbr);

#endif
