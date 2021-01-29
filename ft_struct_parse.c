/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:21:57 by mac               #+#    #+#             */
/*   Updated: 2021/01/29 17:10:49 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_random_func(const char **format, t_options *ft_op)
{
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			ft_op->flag_zero = true;
		if (**format == '-')
		{
			ft_op->flag_minus = true;
			ft_op->flag_zero = false;
		}
		(*format)++;
	}
	if (**format == '*')
	{
		ft_op->width_star = true;
		(*format)++;
	}
	else
	{
		ft_op->width_num = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void		ft_random_func2(const char **f, t_options *ft_op)
{
	char *options;

	options = "cuipsxX%d\0";
	if (**f == '.')
	{
		ft_op->precision = true;
		(*f)++;
		if (**f == '*')
		{
			ft_op->precision_star = true;
			(*f)++;
		}
		else
		{
			ft_op->precision_num = ft_atoi(*f);
			while (ft_isdigit(**f))
				(*f)++;
		}
	}
	if (ft_strchr(options, **f))
	{
		ft_op->type = **f;
		(*f)++;
	}
}

t_options	parse_for_struct(const char **format)
{
	t_options ft_op;

	ft_bzero(&ft_op, sizeof(t_options));
	if (**format == ' ')
	{
		while (**format == ' ')
			(*format)++;
		ft_putchar_fd(' ', 1);
	}
	ft_random_func(format, &ft_op);
	ft_random_func2(format, &ft_op);
	return (ft_op);
}
