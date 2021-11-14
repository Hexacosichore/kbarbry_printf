/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:56:13 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/14 16:58:48 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_putnbr_base(int nbr, int size_base, int mode)
{
	char			*base;
	long long int	n;

	n = (long long int)nbr;
	if (mode == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(-n, size_base, mode);
	}
	else if (n >= size_base)
	{
		ft_putnbr_base(n / size_base, size_base, mode);
		ft_putchar_fd(base[n % size_base], 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;

	va_list(param);
	va_start(param, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_base((int)va_arg(param, int), 10, 1);
			else if (str[i] == 's')
				ft_putstr_fd((char *)va_arg(param, char *), 1);
			else if (str[i] == 'c' || str[i] == '%')
				ft_putchar_fd((char)va_arg(param, int), 1);
			else if (str[i] == 'X')
				ft_putnbr_base((int)va_arg(param, int), 16, 1);
			else if (str[i] == 'x')
				ft_putnbr_base((int)va_arg(param, int), 16, 2);
		}
		else
			ft_putchar_fd(str[i], 1);
	}
	return (1);
}

int	main(void)
{
	ft_printf(" %s ", "blabla");
}