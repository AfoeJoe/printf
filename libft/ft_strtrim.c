/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:36:57 by tkathy            #+#    #+#             */
/*   Updated: 2020/11/16 19:54:59 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_last_front(const char *s1, const char *set)
{
	size_t n;

	n = 0;
	while (*s1)
	{
		if (ft_strchr(set, *s1++) == 0)
			break ;
		n++;
	}
	return (n);
}

static size_t	get_last_back(const char *s1, const char *set, size_t len)
{
	while (len)
	{
		if (ft_strchr(set, s1[len]) == 0)
			break ;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = get_last_front(s1, set);
	if (start == len)
	{
		if ((trimmed = ft_calloc(sizeof(char), 1)) == NULL)
			return (NULL);
		return (trimmed);
	}
	end = get_last_back(s1, set, len);
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
