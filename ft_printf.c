/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:56:13 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/16 16:19:31 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, va_list va)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_base((long long int)va_arg(va, int), 10, 1);
	else if (c == 's')
		ft_putstr_printf((char *)va_arg(va, char *));
	else if (c == 'c')
		ft_putchar_printf((char)va_arg(va, int), 0);
	else if (c == 'X')
		ft_putnbr_base((unsigned long int)va_arg(va, unsigned int), 16, 1);
	else if (c == 'x')
		ft_putnbr_base((unsigned long int)va_arg(va, unsigned int), 16, 2);
	else if (c == '%')
		ft_putchar_printf('%', 0);
	else if (c == 'u')
		ft_putnbr_base((unsigned long int)va_arg(va, unsigned int), 10, 1);
	else if (c == 'p')
		ft_put_ptr((unsigned long long int)va_arg(va, unsigned long long int));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	va;
	int		final;

	va_start(va, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print(str[i], va);
		}
		else
			ft_putchar_printf(str[i], 0);
		i++;
	}
	va_end(va);
	final = ft_putchar_printf('f', 1);
	return (final);
}
