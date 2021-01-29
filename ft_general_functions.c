#include "ft_printf.h"

void ft_putnbr_base_fd(unsigned int num, int fd, char *values)
{
    char c;

    if (num < 16)
    {
        num = values[num];
        write(fd, &num, 1);
    }
    else
    {
        ft_putnbr_base_fd(num / 16, fd, values);
        c = values[num % 16];
        write(fd, &c, 1);
    }
}
void ft_putptr_base_fd(unsigned long num, int fd, char *values)
{
    char c;

    if (num < 16)
    {
        num = values[num];
        write(fd, &num, 1);
    }
    else
    {
        ft_putptr_base_fd(num / 16, fd, values);
        c = values[num % 16];
        write(fd, &c, 1);
    }
}
int ft_hexlen(unsigned int n)
{
    int len;
    len = 0;

    while (n)
    {
        n /= 16;
        len++;
    }
    return (len ? len : 1);
}
int ft_ptrlen(unsigned long n)
{
    int len;
    len = 0;

    while (n)
    {
        n /= 16;
        len++;
    }
    return (len ? len : 1);
}