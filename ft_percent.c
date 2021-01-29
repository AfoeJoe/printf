/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:49:06 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:01:11 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_perc_plus(t_options *op, int *character_count, char c)
{
	while (op->width_num > op->precision_num)
	{
		put_char_increase(c, character_count);
		op->width_num--;
	}
	while (op->precision_num > 1)
	{
		put_char_increase(c, character_count);
		op->precision_num--;
	}
	put_char_increase('%', character_count);
}

int		ft_percent(t_options op, int *character_count)
{
	char c;

	c = (op.flag_zero && !op.precision) ? '0' : ' ';
	op.precision_num = op.precision_num < 1 ? 1 : op.precision_num;
	if (op.flag_minus)
	{
		put_char_increase('%', character_count);
		while (op.precision_num > 1)
		{
			put_char_increase(c, character_count);
			op.precision_num--;
		}
		while (op.width_num-- > op.precision_num)
			put_char_increase(' ', character_count);
	}
	else
		process_perc_plus(&op, character_count, c);
	return (6);
}
