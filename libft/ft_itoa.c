/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <tkathy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:40:10 by tkathy            #+#    #+#             */
/*   Updated: 2020/11/09 20:12:27 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	size_t len;

	len = (n < 0) ? 1 : 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		*iterate(char *ret, int n, size_t len)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n < 10)
	{
		ret[len] = n + '0';
		return (ret);
	}
	else
	{
		ret[len--] = n % 10 + '0';
		return (iterate(ret, n / 10, len));
	}
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	len;

	len = ft_len(n);
	if (len == 0)
		return (NULL);
	if ((ret = malloc(sizeof(char) * len + 1)) == 0)
		return (NULL);
	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	ret[len--] = '\0';
	if (n < 0)
		ret[0] = '-';
	return (iterate(ret, n, len));
}
