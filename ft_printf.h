/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:13:42 by mac               #+#    #+#             */
/*   Updated: 2021/01/29 03:13:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "limits.h"

#include "../libft/libft.h"

int ft_printf(const char *, ...);
int ft_parse(const char *, int *, va_list);
int ft_parse_percent(const char **, int *, va_list);
typedef enum
{
    false,
    true
} bool;
typedef struct printf
{
    bool flag_minus;
    bool flag_zero;
    bool width_star;
    int width_num;
    bool precision_star;
    int precision_num;
    char type;
    bool precision;

} ft_options;
ft_options parse_for_struct(const char **);
int ft_char(ft_options, va_list, int *);
int ft_str(ft_options, va_list, int *);
int ft_ptr(ft_options, va_list, int *);

int ft_num(ft_options, va_list, int *);
int ft_unum(ft_options, va_list, int *);

int ft_num_base(ft_options, va_list, int *);
int ft_num_baseX(ft_options, va_list, int *);
int ft_percent(ft_options, int *);

void ft_putnbr_base_fd(unsigned int, int, char *);
void ft_putptr_base_fd(unsigned long, int, char *);

int ft_hexlen(unsigned int);
int ft_ptrlen(unsigned long);
void put_char_increase(char, int *);
void put_nbr_increase(int, int *, int);
void put_str_increase(char *, int *, int);

void initialise(ft_options *);

#endif
