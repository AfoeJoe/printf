/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:59:34 by mac               #+#    #+#             */
/*   Updated: 2021/01/28 21:26:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int	ret;
	int	character_count;

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
		if((ret = ft_parse(format, &character_count, args)) < 0)
			{
				va_end(args);
				return (-1);
			}
	va_end(args);
	return (character_count);
}
