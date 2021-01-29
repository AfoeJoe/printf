/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:36:16 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:04:10 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_m(t_options *op, int *c_c, unsigned long n, int len)
{
	char	*values;
	char	c;
	int		f;

	values = "0123456789abcdef";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	f = op->precision_num > len ? op->precision_num : len;
	while (op->precision_num > len - 2)
	{
		put_char_increase('0', c_c);
		op->precision_num--;
	}
	if (((op->precision_num <= 0 && op->precision) || !op->precision) && n == 0)
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0x", 1);
	ft_putptr_base_fd(n, 1, values);
	(*c_c) += len;
	while (op->width_num > f)
	{
		put_char_increase(c, c_c);
		op->width_num--;
	}
}

void	p_p(t_options *op, int *c_c, unsigned long n, int len)
{
	char	*values;
	char	c;
	int		f;

	values = "0123456789abcdef";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	f = op->precision_num > len ? op->precision_num : len;
	while (op->width_num > f)
	{
		put_char_increase(c, c_c);
		op->width_num--;
	}
	if (((op->precision_num <= 0 && op->precision) || !op->precision) && n == 0)
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0x", 1);
	while (op->precision_num > len - 2)
	{
		put_char_increase('0', c_c);
		op->precision_num--;
	}
	ft_putptr_base_fd(n, 1, values);
	(*c_c) += len;
}

int		ft_ptr(t_options op, va_list a, int *c_c)
{
	unsigned long	num;
	int				len;

	len = 0;
	op.width_num = (op.width_star) ? va_arg(a, int) : op.width_num;
	op.precision_num = (op.precision_star) ? va_arg(a, int) : op.precision_num;
	initialise(&op);
	num = va_arg(a, unsigned long);
	len = ft_ptrlen(num) + 2;
	if (op.precision && op.precision_num == 0 && num == 0)
	{
		(*c_c) += 2;
		while (op.width_num-- > 2)
			put_char_increase(' ', c_c);
		ft_putstr_fd("0x", 1);
	}
	else
		(op.flag_minus) ? p_m(&op, c_c, num, len) : p_p(&op, c_c, num, len);
	return (3);
}
