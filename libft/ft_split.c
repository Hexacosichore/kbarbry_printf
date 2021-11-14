/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:00:32 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/04 13:30:12 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t size)
{
	char	*res;

	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	ft_memcpy(res, s, size);
	res[size] = 0;
	return (res);
}

static void	*ft_memalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		return (0);
	ft_bzero(res, size);
	return (res);
}

static int	split_len(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = ft_memalloc((split_len(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_strndup(&s[index], i - index);
			index = -1;
		}
		i++;
	}
	return (split);
}
