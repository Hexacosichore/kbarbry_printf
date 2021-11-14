/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:08 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/04 16:49:18 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*nbr;

	if (!s)
		return (NULL);
	nbr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nbr)
		return (0);
	i = 0;
	while (s[i])
	{
		nbr[i] = f(i, s[i]);
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}
