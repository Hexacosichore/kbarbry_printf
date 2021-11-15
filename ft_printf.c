/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:56:13 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/15 18:19:39 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putchar_printf(char c, t_comptor *comptor)
{
	write(1, &c, 1);
	comptor->size++;
}

void	ft_putstr_printf(char *s, t_comptor *comptor)
{
	int	i;

	i = 0;
	if (!s)
	{
		comptor->size++;
		ft_putstr_printf("(null)", comptor);
	}
	else
	{
		while (s[i])
		{
			ft_putchar_printf(s[i], comptor);
			i++;
		}
	}
}

void	ft_putnbr_base(int nbr, int size_base, int mode, t_comptor *comptor)
{
	char		*base;
	long int	n;

	n = (long long int)nbr;
	if (mode == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar_printf('-', comptor);
		ft_putnbr_base(-n, size_base, mode, comptor);
	}
	else if (n >= size_base)
	{
		ft_putnbr_base(n / size_base, size_base, mode, comptor);
		ft_putchar_printf(base[n % size_base], comptor);
	}
	else
		ft_putchar_printf(n + '0', comptor);
}

// void	ft_put_ptr(void *ptr, t_comptor *comptor)
// {
	
// }

void	ft_print(char c, va_list va, t_comptor *comptor)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_base((int)va_arg(va, int), 10, 1, comptor);
	else if (c == 's')
		ft_putstr_printf((char *)va_arg(va, char *), comptor);
	else if (c == 'c')
		ft_putchar_printf((char)va_arg(va, int), comptor);
	else if (c == 'X')
		ft_putnbr_base((int)va_arg(va, int), 16, 1, comptor);
	else if (c == 'x')
		ft_putnbr_base((int)va_arg(va, int), 16, 2, comptor);
	else if (c == '%')
		ft_putchar_printf('%', comptor);
	else if (c == 'u')
		ft_putnbr_base((unsigned int)va_arg(va, unsigned int), 10, 1, comptor);
	//else if (c == 'p')
		//ft_put_ptr((void *)va_arg(va, void *), comptor);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	t_comptor	*comptor;
	va_list		va;

	va_start(va, str);
	i = 0;
	comptor = malloc(sizeof(t_comptor));
	if (!comptor)
		return (0);
	comptor->size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print(str[i], va, comptor);
		}
		else
			ft_putchar_printf(str[i], comptor);
		i++;
	}
	va_end(va);
	free(comptor);
	return (comptor->size);
}

// int	main(void)
// {
// 	//int	size;
// 	int	size2;
// 	char *str = "blabla";

// 	//size = ft_printf(" NULL %p NULL ", str);
// 	size2 = printf("\n NULL %p NULL ", str);
// 	printf("\n %d %d ", 1, size2);
// }
