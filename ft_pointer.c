#include "ft_printf.h"

void ft_pstr(char *s, int fd, int pl)
{
    int i;

    i = 0;
    if (!s || !fd)
        return;
    while (s[i] && i < pl)
    {
        write(fd, &s[i++], 1);
    }
}

int ft_ptr(ft_options op, va_list args, int *character_count)
{
    unsigned long num;
    int len;
    char c;
    int n;
    char *values;
    values = "0123456789abcdef";

    len = 0;
    op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;

    op.precision_num = (op.precision_star) ? va_arg(args, int) : op.precision_num;
    c = (op.flag_zero && !op.precision) ? '0' : ' ';
    num = va_arg(args, unsigned long);

    len = ft_ptrlen(num) + 2;
    if (op.precision && op.precision_num == 0 && num == 0)
    {
        (*character_count) += 2;
        while (op.width_num-- > 2)
            put_char_increase(' ', character_count);
        ft_putstr_fd("0x", 1);
    }
    else
    {
        if (op.flag_minus)
        {
            n = op.precision_num > len ? op.precision_num : len;

            while (op.precision_num > len - 2)
            {
                put_char_increase('0', character_count);
                op.precision_num--;
            }
            (((op.precision_num <= 0 && op.precision) || !op.precision) && num == 0) ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0x", 1);

            ft_putptr_base_fd(num, 1, values);
            (*character_count) += len;

            while (op.width_num > n)
            {
                put_char_increase(c, character_count);
                op.width_num--;
            }
        }
        else
        {
            n = op.precision_num > len ? op.precision_num : len;
            while (op.width_num > n)
            {
                put_char_increase(c, character_count);
                op.width_num--;
            }
            (((op.precision_num <= 0 && op.precision) || !op.precision) && num == 0) ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0x", 1);

            while (op.precision_num > len - 2)
            {
                put_char_increase('0', character_count);
                op.precision_num--;
            }

            ft_putptr_base_fd(num, 1, values);
            (*character_count) += len;
        }
    }
    return (3);
}