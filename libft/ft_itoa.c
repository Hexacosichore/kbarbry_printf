/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:40:19 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/04 12:41:42 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	unsigned int	nabs;

	len = ft_nbrlen(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	nabs = n;
	if (n < 0)
	{
		nbr[0] = '-';
		nabs = -n;
	}
	while (1)
	{
		nbr[--len] = (nabs % 10) + '0';
		nabs /= 10;
		if (nabs == 0)
			return (nbr);
	}
}
