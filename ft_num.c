#include "ft_printf.h"

int ft_numlen(int n)
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
int ft_num(ft_options op, va_list args, int *character_count)
{
    int numi;
    int len;
    char c;
    int n;
    int neg;

    neg = 0;
    len = 0;
    op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;
    initialise(&op);
    op.precision_num = (op.precision_star) ? va_arg(args, int) : op.precision_num;
    c = (op.flag_zero || op.precision_num) ? '0' : ' ';
    if ((numi = va_arg(args, int)) < 0)
        neg = 1;
    if (!op.flag_minus && !op.flag_zero)
    {
        len = ft_numlen(numi);
        n = len > op.precision_num ? len : op.precision_num;
        if (neg)
            op.width_num--;
        while (op.width_num - n > 0)
        {
            put_char_increase(' ', character_count);
            op.width_num--;
        }

        if (neg)
        {
            (numi != INT_MIN) ? ft_putchar_fd('-', 1) : -1 == -1;
            numi = -1 * numi;
            (*character_count)++;
        }

        while (op.precision_num > len)
        {
            op.precision_num--;
            put_char_increase('0', character_count);
            op.width_num--;
        }
        if (op.precision_num == 0 && op.precision && numi == 0)
        {
            while (op.width_num--)
                put_char_increase(' ', character_count);
            return (2);
        }
        put_nbr_increase(numi, character_count, len);
    }

    else if (op.flag_minus)
    {

        len = ft_numlen(numi);
        n = len > op.precision_num ? len : op.precision_num;
        if (neg)
        {
            (numi != INT_MIN) ? ft_putchar_fd('-', 1) : -1 == -1;
            (*character_count)++;
            numi = -numi;
            op.width_num--;
        }
        while (op.precision_num > len)
        {
            put_char_increase('0', character_count);
            op.precision_num--;
            op.width_num--;
        }
        if (op.precision_num == 0 && op.precision && numi == 0)
        {
            while (op.width_num-- > 0)
                put_char_increase(' ', character_count);
            return (2);
        }
        put_nbr_increase(numi, character_count, len);
        while (op.width_num-- > len)
            put_char_increase(' ', character_count);
    }

    else if (op.flag_zero)
    {
        len = ft_numlen(numi);
        n = len > op.precision_num ? len : op.precision_num;
        if (neg)
            op.width_num--;
        while (op.width_num > n && op.precision_num)
        {
            (op.precision_num) ? put_char_increase(' ', character_count)
                               : put_char_increase('0', character_count);

            op.width_num--;
        }
        if (neg)
        {
            (numi != INT_MIN) ? ft_putchar_fd('-', 1) : -1 == -1;
            numi = -numi;
            (*character_count)++;
        }
        while (op.width_num > n)
        {
            put_char_increase('0', character_count);
            op.width_num--;
        }

        while (op.precision_num > len)
        {
            put_char_increase('0', character_count);
            op.width_num--;
            op.precision_num--;
        }
        if (op.precision_num == 0 && op.precision && numi == 0)
        {
            while (op.width_num--)
                put_char_increase(' ', character_count);
            return (2);
        }
        put_nbr_increase(numi, character_count, len);
    }

    return (6);
}