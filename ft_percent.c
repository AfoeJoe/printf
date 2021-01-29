#include "ft_printf.h"

int ft_percent(ft_options op, int *character_count)
{
    char c;
    c = (op.flag_zero && !op.precision) ? '0' : ' ';
    op.precision_num = op.precision_num < 1 ? 1 : op.precision_num;
    if (op.flag_minus)
    {
        put_char_increase('%', character_count);
        while (op.precision_num > 1)
        {
            put_char_increase(c, character_count);
            op.precision_num--;
        }
        while (op.width_num-- > op.precision_num)
            put_char_increase(' ', character_count);
    }
    else
    {
        while (op.width_num > op.precision_num)
        {
            put_char_increase(c, character_count);
            op.width_num--;
        }
        while (op.precision_num > 1)
        {
            put_char_increase(c, character_count);
            op.precision_num--;
        }
        put_char_increase('%', character_count);
    }
    return (6);
}