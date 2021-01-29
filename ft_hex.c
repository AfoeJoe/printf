/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:53:32 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:02:03 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_x_m(t_options *op, int *character_count, unsigned int num, int len)
{
	char	*values;
	int		n;
	char	c;

	values = "0123456789abcdef";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	n = op->precision_num > len ? op->precision_num : len;
	while (op->precision_num > len)
	{
		ft_putchar_fd('0', 1);
		(*character_count)++;
		op->precision_num--;
	}
	ft_putnbr_base_fd(num, 1, values);
	(*character_count) += len;
	while (op->width_num > n)
	{
		ft_putchar_fd(c, 1);
		(*character_count)++;
		op->width_num--;
	}
}

void	p_x_p(t_options *op, int *character_count, unsigned int num, int len)
{
	char	*values;
	int		n;
	char	c;

	values = "0123456789abcdef";
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
	n = op->precision_num > len ? op->precision_num : len;
	while (op->width_num > n)
	{
		ft_putchar_fd(c, 1);
		(*character_count)++;
		op->width_num--;
	}
	while (op->precision_num > len)
	{
		ft_putchar_fd('0', 1);
		(*character_count)++;
		op->precision_num--;
	}
	ft_putnbr_base_fd(num, 1, values);
	(*character_count) += len;
}

int		ft_num_base(t_options op, va_list a, int *c_c)
{
	int				l;
	unsigned int	n;

	l = 0;
	op.width_num = (op.width_star) ? va_arg(a, int) : op.width_num;
	op.precision_num = (op.precision_star) ? va_arg(a, int) : op.precision_num;
	initialise(&op);
	n = va_arg(a, unsigned int);
	l = ft_hexlen(n);
	if (op.precision && op.precision_num == 0 && n == 0)
	{
		while (op.width_num-- > 0)
		{
			ft_putchar_fd(' ', 1);
			(*c_c)++;
		}
	}
	else
		(op.flag_minus) ? p_x_m(&op, c_c, n, l) : p_x_p(&op, c_c, n, l);
	return (3);
}
