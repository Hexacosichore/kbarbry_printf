/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:18:41 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/04 18:29:51 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = (char *)malloc(s1len + s2len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s1, s1len + 1);
	ft_strlcat(dest, (char *)s2, s1len + s2len + 1);
	return (dest);
}
