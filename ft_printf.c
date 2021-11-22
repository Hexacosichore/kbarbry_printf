/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:56:13 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/20 18:52:48 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, va_list va, t_n *n)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_base((long long int)va_arg(va, int), 10, 1, n);
	else if (c == 's')
		ft_putstr_printf((char *)va_arg(va, char *), n);
	else if (c == 'c')
		ft_putchar_printf((char)va_arg(va, int), n);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)va_arg(va, unsigned int), 16, 1, n);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)va_arg(va, unsigned int), 16, 2, n);
	else if (c == '%')
		ft_putchar_printf('%', n);
	else if (c == 'u')
		ft_putnbr_base((unsigned long int)va_arg(va, unsigned int), 10, 1, n);
	else if (c == 'p')
		ft_put_ptr((unsigned long int)va_arg(va, unsigned long int), n);
	else
		ft_putchar_printf('c', n);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	va;
	t_n		n;

	n.cmp = 0;
	va_start(va, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print(str[i], va, &n);
		}
		else
			ft_putchar_printf(str[i], &n);
		i++;
	}
	va_end(va);
	return (n.cmp);
}
