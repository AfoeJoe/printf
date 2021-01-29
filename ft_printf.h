/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:13:42 by mac               #+#    #+#             */
/*   Updated: 2021/01/29 17:10:52 by tkathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "limits.h"
# include "../libft/libft.h"

int				ft_printf(const char *format, ...);
int				ft_parse(const char *format, int *c_c, va_list a);
int				ft_p_percent(const char **format, int *c_c, va_list a);
typedef enum
{
	false,
	true
}	t_bool;
typedef struct	s_printf
{
	t_bool	flag_minus;
	t_bool	flag_zero;
	t_bool	width_star;
	int		width_num;
	t_bool	precision_star;
	int		precision_num;
	char	type;
	t_bool	precision;
}				t_options;
t_options		parse_for_struct(const char **format);
int				ft_char(t_options op, va_list args, int *c_c);
int				ft_str(t_options op, va_list args, int *c_c);
int				ft_ptr(t_options op, va_list args, int *c_c);
int				ft_num(t_options op, va_list args, int *c_c);
int				ft_unum(t_options op, va_list args, int *c_c);
int				ft_num_base(t_options op, va_list args, int *c_c);
int				ft_num_base_xc(t_options op, va_list args, int *c_c);
int				ft_percent(t_options op, int *c_c);
void			ft_putnbr_base_fd(unsigned int num, int fd, char *values);
void			ft_putptr_base_fd(unsigned long num, int fd, char *values);
int				ft_hexlen(unsigned int num);
int				ft_ptrlen(unsigned long num);
void			put_char_increase(char c, int *c_c);
void			put_nbr_increase(int numi, int *c_c, int len);
void			put_str_increase(char *str, int *c_c, int len);
int				ft_numlen(int n);
void			handle_neg(int neg, int numi, int *c_c);
void			handle_neg_2(int neg, int numi, int *c_c, t_options *op);
void			initialise(t_options *op);
int				handle_special(t_options *op, int numi, int *c_c);

#endif
