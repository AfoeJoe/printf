#include "ft_printf.h"

void ft_putnbr(unsigned int n, int fd)
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
int ft_unumlen(unsigned int n)
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
int ft_unum(ft_options op, va_list args, int *character_count)
{
    int len;
    unsigned int num;
    char c;
    int n;

    len = 0;
    op.width_num = (op.width_star) ? va_arg(args, int) : op.width_num;

    op.precision_num = (op.precision_star) ? va_arg(args, int) : op.precision_num;
    c = (op.flag_zero && !op.precision) ? '0' : ' ';
    num = va_arg(args, unsigned int);

    len = ft_unumlen(num);
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
            ft_putnbr(num, 1);
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
            ft_putnbr(num, 1);
            (*character_count) += len;
        }
    }
    return (2);
}