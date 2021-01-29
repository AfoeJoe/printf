/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:46:08 by mac               #+#    #+#             */
/*   Updated: 2021/01/29 17:01:38 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_options op, va_list args, int *character_count)
{
	char c;

	op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;
	initialise(&op);
	c = va_arg(args, int);
	if (op.flag_minus)
	{
		if (op.width_num)
		{
			put_char_increase(c, character_count);
			while (op.width_num-- > 1)
				put_char_increase(' ', character_count);
		}
		else
			put_char_increase(c, character_count);
	}
	else if (op.width_num)
	{
		while (op.width_num-- > 1)
			put_char_increase(' ', character_count);
		put_char_increase(c, character_count);
	}
	else
		put_char_increase(c, character_count);
	return (1);
}
