/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:24:15 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/30 00:51:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void inside_p_n_z(t_options *op, int *c_c, int neg, int n)
{
	if (neg)
		op->width_num--;
	while (op->width_num > n && op->precision)
	{
		if (op->precision_num >= 0)
			put_char_increase(' ', c_c);
		else
			put_char_increase('0', c_c);
		op->width_num--;
	}
}

void p_n_n(t_options *op, int *c_c, int numi, int neg)
{
	int len;
	int n;

	len = ft_numlen(numi);
	n = len > op->precision_num ? len : op->precision_num;
	(neg) ? op->width_num-- : -1 == -1;
	while (op->width_num - n > 0)
	{
		put_char_increase(' ', c_c);
		op->width_num--;
	}
	handle_neg(neg, numi, c_c);
	while (op->precision_num > len)
	{
		op->precision_num--;
		put_char_increase('0', c_c);
		op->width_num--;
	}
	if (op->precision_num == 0 && op->precision && numi == 0)
	{
		while (op->width_num--)
			put_char_increase(' ', c_c);
		return;
	}
	put_nbr_increase(numi, c_c, len);
}

void p_n_z(t_options *op, int *c_c, int numi, int neg)
{
	int len;
	int n;
	int ret;

	len = ft_numlen(numi);
	n = len > op->precision_num ? len : op->precision_num;
	(op->precision_num >= 0) ? -1 : handle_neg(neg, numi, c_c);
	inside_p_n_z(op, c_c, neg, n);
	(op->precision_num >= 0) ? handle_neg(neg, numi, c_c) : -1;
	while (op->width_num > n)
	{
		put_char_increase('0', c_c);
		op->width_num--;
	}
	while (op->precision_num > len)
	{
		put_char_increase('0', c_c);
		op->width_num--;
		op->precision_num--;
	}
	if ((ret = handle_special(op, numi, c_c)) == 1)
		return;
	put_nbr_increase(numi, c_c, len);
}

void p_n_m(t_options *op, int *c_c, int numi, int neg)
{
	int len;
	int n;

	len = ft_numlen(numi);
	n = len > op->precision_num ? len : op->precision_num;
	handle_neg_2(neg, numi, c_c, op);
	while (op->precision_num > len)
	{
		put_char_increase('0', c_c);
		op->precision_num--;
		op->width_num--;
	}
	if (op->precision_num == 0 && op->precision && numi == 0)
	{
		while (op->width_num-- > 0)
			put_char_increase(' ', c_c);
		return;
	}
	put_nbr_increase(numi, c_c, len);
	while (op->width_num-- > len)
		put_char_increase(' ', c_c);
}

int ft_num(t_options op, va_list args, int *c_c)
{
	int numi;
	int neg;

	neg = 0;
	op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;
	initialise(&op);
	if (op.precision_star)
		op.precision_num = va_arg(args, int);
	if ((numi = va_arg(args, int)) < 0)
	{
		numi = -1 * numi;
		neg = 1;
	}
	if (!op.flag_minus && !op.flag_zero)
		p_n_n(&op, c_c, numi, neg);
	else if (op.flag_minus)
		p_n_m(&op, c_c, numi, neg);
	else if (op.flag_zero)
		p_n_z(&op, c_c, numi, neg);
	return (6);
}
