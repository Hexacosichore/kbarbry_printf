/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:49:19 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/04 12:31:32 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char test, char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == test)
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (ft_is_in_set((char)s1[i], (char *)set) != -1 && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_is_in_set((char)s1[i], (char *)set) != -1 && i > 0)
		i--;
	return (ft_substr(s1, start, i + 1 - start));
}
