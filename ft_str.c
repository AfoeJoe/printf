/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:16:14 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:05:12 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s, int fd, int pl)
{
	int i;

	i = 0;
	if (!s || !fd)
		return (0);
	while (s[i] && i < pl)
	{
		write(fd, &s[i++], 1);
	}
	return (i);
}

void	random_no_minus(t_options op, int *character_count, char *str, int len)
{
	char precision_flag;

	precision_flag = (op.flag_zero && !op.precision) ? '0' : ' ';
	if (op.precision)
	{
		while (op.width_num-- > op.precision_num)
			put_char_increase(' ', character_count);
		(*character_count) += ft_putstr(str, 1, op.precision_num);
	}
	else
	{
		while (op.width_num-- > len)
			put_char_increase(precision_flag, character_count);
		put_str_increase(str, character_count, len);
	}
}

void	random_minus(t_options op, int *character_count, char *str, int len)
{
	char precision_flag;

	precision_flag = (op.flag_zero && !op.precision) ? '0' : ' ';
	if (op.precision)
	{
		(*character_count) += ft_putstr(str, 1, op.precision_num);
		while (op.width_num-- > op.precision_num)
			put_char_increase(precision_flag, character_count);
	}
	else
	{
		put_str_increase(str, character_count, len);
		while (op.width_num-- > len)
			put_char_increase(' ', character_count);
	}
}

int		ft_str(t_options op, va_list a, int *character_count)
{
	char	*str;
	int		len;

	len = 0;
	op.width_num = (op.width_star) ? va_arg(a, int) : op.width_num;
	op.precision_num = (op.precision_star) ? va_arg(a, int) : op.precision_num;
	initialise(&op);
	str = va_arg(a, char *);
	if (!str)
	{
		str = "(null)";
		if (op.precision_num < 0 && op.width_num == 0)
		{
			put_str_increase(str, character_count, 6);
			return (4);
		}
	}
	len = ft_strlen(str);
	if (op.precision && op.precision_num > len)
		op.precision_num = len;
	if (op.flag_minus)
		random_minus(op, character_count, str, len);
	else
		random_no_minus(op, character_count, str, len);
	return (len);
}
