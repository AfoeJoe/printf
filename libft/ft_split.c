/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:12:06 by tkathy            #+#    #+#             */
/*   Updated: 2020/11/15 19:19:51 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			while (*s && *s == c)
				s++;
			count++;
			continue ;
		}
		s++;
	}
	return ((*(--s) == c) ? count : count + 1);
}

static int	get_word_len(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s++ != c)
		count++;
	return (count);
}

static char	**get_result(char **arr, char const *s, size_t word_no, char c)
{
	size_t i;
	size_t word_len;

	i = 0;
	while (*s && i < word_no)
	{
		word_len = get_word_len(s, c);
		if ((arr[i] = ft_substr(s, 0, word_len)) == 0)
		{
			while (i)
				free(arr[i--]);
			free(arr);
		}
		s = s + word_len;
		while (*s == c)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_no;

	if (!s || !c)
		return (0);
	while (*s && *s == c)
		s++;
	word_no = count_words(s, c);
	if ((arr = (char **)malloc(sizeof(char *) * (word_no + 1))) == 0)
		return (NULL);
	return (get_result(arr, s, word_no, c));
}
