#include "ft_printf.h"

int ft_num_base(ft_options op, va_list args, int *character_count)
{
    int len;
    unsigned int num;
    char c;
    int n;
    char *values;
    values = "0123456789abcdef";

    len = 0;
    op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;

    op.precision_num = (op.precision_star) ? va_arg(args, int) : op.precision_num;
    c = (op.flag_zero && !op.precision) ? '0' : ' ';
    num = va_arg(args, unsigned int);

    len = ft_hexlen(num);
    if (op.precision && op.precision_num == 0 && num == 0)
    {
        while (op.width_num-- > 0)
        {
            ft_putchar_fd(' ', 1);
            (*character_count)++;
        }
    }
    else
    {
        if (op.flag_minus)
        {
            n = op.precision_num > len ? op.precision_num : len;

            while (op.precision_num > len)
            {
                ft_putchar_fd('0', 1);
                (*character_count)++;

                op.precision_num--;
            }
            ft_putnbr_base_fd(num, 1, values);
            (*character_count) += len;

            while (op.width_num > n)
            {
                ft_putchar_fd(c, 1);
                (*character_count)++;

                op.width_num--;
            }
        }
        else
        {
            n = op.precision_num > len ? op.precision_num : len;
            while (op.width_num > n)
            {
                ft_putchar_fd(c, 1);
                (*character_count)++;

                op.width_num--;
            }
            while (op.precision_num > len)
            {
                ft_putchar_fd('0', 1);
                (*character_count)++;

                op.precision_num--;
            }
            ft_putnbr_base_fd(num, 1, values);
            (*character_count) += len;
        }
    }
    return (3);
}