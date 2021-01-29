/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:03:44 by tkathy            #+#    #+#             */
/*   Updated: 2021/01/29 17:04:44 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int n, int fd)
{
	if (n == 4294967295u)
		write(fd, "4294967295", 10);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n < 10)
		{
			n = (char)n + '0';
			write(fd, &n, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			n = n % 10 + '0';
			write(fd, &n, 1);
		}
	}
}

int		ft_unumlen(unsigned int n)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len ? len : 1);
}

void	p_u_p(t_options *op, int *character_count, unsigned int num, int len)
{
	int		n;
	char	c;

	n = op->precision_num > len ? op->precision_num : len;
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
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
	ft_putnbr(num, 1);
	(*character_count) += len;
}

void	p_u_m(t_options *op, int *character_count, unsigned int num, int len)
{
	int		n;
<<<<<<< HEAD

	n = op->precision_num > len ? op->precision_num : len;
=======
	char	c;

	n = op->precision_num > len ? op->precision_num : len;
	c = (op->flag_zero && !op->precision) ? '0' : ' ';
>>>>>>> 2f445daa33595998223b419d0d51f7d23b9e4a89
	while (op->precision_num > len)
	{
		ft_putchar_fd('0', 1);
		(*character_count)++;
		op->precision_num--;
	}
	ft_putnbr(num, 1);
	(*character_count) += len;
	while (op->width_num > n)
	{
<<<<<<< HEAD
		ft_putchar_fd(' ', 1);
=======
		ft_putchar_fd(c, 1);
>>>>>>> 2f445daa33595998223b419d0d51f7d23b9e4a89
		(*character_count)++;
		op->width_num--;
	}
}

int		ft_unum(t_options op, va_list args, int *c_c)
{
	int				len;
	unsigned int	num;

	len = 0;
	op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;
	if (op.precision_star)
<<<<<<< HEAD
		op.precision_num = va_arg(args, int);
=======
		va_arg(args, int);
>>>>>>> 2f445daa33595998223b419d0d51f7d23b9e4a89
	initialise(&op);
	num = va_arg(args, unsigned int);
	len = ft_unumlen(num);
	if (op.precision && op.precision_num == 0 && num == 0)
	{
		while (op.width_num-- > 0)
		{
			ft_putchar_fd(' ', 1);
			(*c_c)++;
		}
	}
	else
		(op.flag_minus) ? p_u_m(&op, c_c, num, len) : p_u_p(&op, c_c, num, len);
	return (2);
}
