/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:08:30 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:03:32 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_neg(int neg, int num, int *c_c)
{
	if (neg)
	{
		(num != INT_MIN) ? ft_putchar_fd('-', 1) : -1 == -1;
		(*c_c)++;
	}
}

void	handle_neg_2(int neg, int num, int *c_c, t_options *op)
{
	if (neg)
	{
		(num != INT_MIN) ? ft_putchar_fd('-', 1) : -1 == -1;
		(*c_c)++;
		op->width_num--;
	}
}
