/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:59:34 by mac               #+#    #+#             */
/*   Updated: 2021/01/29 16:59:34 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_percent(const char **format, int *character_count, va_list args)
{
	t_options ft_op;

	ft_op = parse_for_struct(format);
	if (ft_op.type == 'c')
		return (ft_char(ft_op, args, character_count));
	else if (ft_op.type == 's')
		return (ft_str(ft_op, args, character_count));
	else if (ft_op.type == 'd' || ft_op.type == 'i')
		return (ft_num(ft_op, args, character_count));
	else if (ft_op.type == 'u')
		return (ft_unum(ft_op, args, character_count));
	else if (ft_op.type == 'x')
		return (ft_num_base(ft_op, args, character_count));
	else if (ft_op.type == 'X')
		return (ft_num_base_xc(ft_op, args, character_count));
	else if (ft_op.type == 'p')
		return (ft_ptr(ft_op, args, character_count));
	else if (ft_op.type == '%')
		return (ft_percent(ft_op, character_count));
	else if (**format == '\0')
		return (0);
	else
		return (-1);
	return (0);
}

int		ft_parse(const char *format, int *character_count, va_list args)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((ret = ft_p_percent(&format, character_count, args)) < 0)
				return (ret);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			(*character_count)++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		character_count;

	ret = 0;
	character_count = 0;
	va_start(args, format);
	if (!format[0])
	{
		write(1, "", 0);
		return (0);
	}
	if (format[0] == '%' && !format[1])
		return (0);
	else
	{
		if ((ret = ft_parse(format, &character_count, args)) < 0)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (character_count);
}
