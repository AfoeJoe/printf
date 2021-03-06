/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:33:10 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:05:43 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbr_increase(int numi, int *character_count, int len)
{
	ft_putnbr_fd(numi, 1);
	(*character_count) += len;
}

void	put_char_increase(char c, int *character_count)
{
	ft_putchar_fd(c, 1);
	(*character_count)++;
}

void	put_str_increase(char *str, int *character_count, int len)
{
	ft_putstr_fd(str, 1);
	(*character_count) += len;
}

void	initialise(t_options *op)
{
	if (op->width_num < 0)
	{
		op->width_num = -1 * op->width_num;
		op->flag_minus = true;
	}
	if (op->precision_num < 0)
	{
		op->precision_num = 0;
		op->precision = false;
	}
}
