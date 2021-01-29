/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexC.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:08:00 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:02:26 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_xc_m(t_options *op, int *c_c, unsigned int num, int len)
{
	char	*values;
	int		n;
	char	c;

	values = "0123456789ABCDEF";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	n = op->precision_num > len ? op->precision_num : len;
	while (op->precision_num > len)
	{
		ft_putchar_fd('0', 1);
		(*c_c)++;
		op->precision_num--;
	}
	ft_putnbr_base_fd(num, 1, values);
	(*c_c) += len;
	while (op->width_num > n)
	{
		ft_putchar_fd(c, 1);
		(*c_c)++;
		op->width_num--;
	}
}

void	p_xc_p(t_options *op, int *c_c, unsigned int num, int len)
{
	char	*values;
	int		n;
	char	c;

	values = "0123456789ABCDEF";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	n = op->precision_num > len ? op->precision_num : len;
	while (op->width_num > n)
	{
		ft_putchar_fd(c, 1);
		(*c_c)++;
		op->width_num--;
	}
	while (op->precision_num > len)
	{
		ft_putchar_fd('0', 1);
		(*c_c)++;
		op->precision_num--;
	}
	ft_putnbr_base_fd(num, 1, values);
	(*c_c) += len;
}

int		ft_num_base_xc(t_options op, va_list a, int *c_c)
{
	int				len;
	unsigned int	num;

	len = 0;
	op.width_num = (op.width_star) ? va_arg(a, int) : op.width_num;
	op.precision_num = (op.precision_star) ? va_arg(a, int) : op.precision_num;
	initialise(&op);
	num = va_arg(a, unsigned int);
	len = ft_hexlen(num);
	if (op.precision && op.precision_num == 0 && num == 0)
	{
		while (op.width_num-- > 0)
		{
			ft_putchar_fd(' ', 1);
			(*c_c)++;
		}
	}
	else
	{
		if (op.flag_minus)
			p_xc_m(&op, c_c, num, len);
		else
			p_xc_p(&op, c_c, num, len);
	}
	return (3);
}
