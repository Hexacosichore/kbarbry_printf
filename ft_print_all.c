/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:16:30 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/18 15:14:56 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, t_n *n)
{
	write(1, &c, 1);
	n->cmp++;
}

void	ft_putstr_printf(char *s, t_n *n)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr_printf("(null)", n);
	else
	{
		while (s[i])
		{
			ft_putchar_printf(s[i], n);
			i++;
		}
	}
}

void	ft_putnbr_base(long long int nbr, int size, int mode, t_n *n)
{
	int		nbrf[50];
	char	*base;
	int		i;

	i = 0;
	if (mode == 1)
		base = "0123456789ABCDEF";
	if (mode == 2)
		base = "0123456789abcdef";
	if (nbr < 0 && size == 10)
	{
		ft_putchar_printf('-', n);
		nbr = -nbr;
	}
	if (!nbr)
		ft_putchar_printf('0', n);
	while (nbr)
	{
		nbrf[i] = nbr % size;
		nbr = nbr / size;
		i++;
	}
	while (--i >= 0)
		ft_putchar_printf(base[nbrf[i]], n);
}

void	ft_putptr_base(unsigned long int nbr, t_n *n)
{
	int		nbrf[50];
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
		ft_putchar_printf('0', n);
	while (nbr)
	{
		nbrf[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_printf(base[nbrf[i]], n);
}

void	ft_put_ptr(unsigned long int ptr, t_n *n)
{
	ft_putstr_printf("0x", n);
	if (!ptr)
		ft_putchar_printf('0', n);
	else
		ft_putptr_base((unsigned long int)ptr, n);
}
