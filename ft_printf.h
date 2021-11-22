/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:05:40 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/18 15:15:38 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//struct

typedef struct s_n
{
	int	cmp;
}				t_n;

//ft_print_all.c

void	ft_putchar_printf(char c, t_n *n);
void	ft_putstr_printf(char *s, t_n *n);
void	ft_putnbr_base(long long int nbr, int size, int mode, t_n *n);
void	ft_putptr_base(unsigned long int nbr, t_n *n);
void	ft_put_ptr(unsigned long int ptr, t_n *n);

//ft_printf.c

void	ft_print(char c, va_list va, t_n *n);
int		ft_printf(const char *str, ...);

#endif
