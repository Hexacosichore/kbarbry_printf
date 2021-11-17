/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:16:30 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/16 15:26:37 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c, int mode)
{
	static int	cpt;

	if (mode == 1)
		return (cpt);
	write(1, &c, 1);
	cpt++;
	return (1);
}

void	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr_printf("(null)");
	else
	{
		while (s[i])
		{
			ft_putchar_printf(s[i], 0);
			i++;
		}
	}
}

void	ft_putnbr_base(long long int nbr, int size, int mode)
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
		ft_putchar_printf('-', 0);
		nbr = -nbr;
	}
	if (nbr == 0)
		ft_putchar_printf('0', 0);
	while (nbr)
	{
		nbrf[i] = nbr % size;
		nbr = nbr / size;
		i++;
	}
	while (--i >= 0)
		ft_putchar_printf(base[nbrf[i]], 0);
}

void	ft_putptr_base(unsigned long int nbr)
{
	int		nbrf[50];
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
		ft_putchar_printf('0', 0);
	while (nbr)
	{
		nbrf[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_printf(base[nbrf[i]], 0);
}

void	ft_put_ptr(unsigned long int ptr)
{
	ft_putstr_printf("0x");
	if (!ptr)
		ft_putchar_printf('0', 0);
	else
		ft_putptr_base((unsigned long int)ptr);
}
