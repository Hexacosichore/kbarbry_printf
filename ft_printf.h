/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:05:40 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/16 15:26:58 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//ft_print_all.c

int		ft_putchar_printf(char c, int mode);
void	ft_putstr_printf(char *s);
void	ft_putnbr_base(long long int nbr, int size, int mode);
void	ft_putptr_base(unsigned long int nbr);
void	ft_put_ptr(unsigned long int ptr);

//ft_printf.c

void	ft_print(char c, va_list va);
int		ft_printf(const char *str, ...);

#endif
