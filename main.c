#include "ft_printf.h"
#include "limits.h"

int main(void)
{
    printf("My PrintF Prin◊ting\n*****************\n");
    ft_printf("%5");
    //ft_printf("%-19dj\n", INT_MAX + 1);

    printf("Original PrintF Printing\n*****************\n");
    //printf("%-19dj\n", INT_MAX

    //   First line of code: {return test("%00-s", s_hidden);}
    //       expected return value : 6
    //       your return value     : 2
    //       expected output : "hi low"
    //       your output     : "-s"
    //       expected (nonprintable as hex) : "hi low"
    //       actual   (nonprintable as hex) : "-s"

    // Test 130 (s_undefbehav_0_width_9) : FAILED.
    //     First line of code: {return test("%09s", s_hidden);}
    //       expected return value : 9
    //       your return value     : 9
    //       expected output : "000hi low"
    //       your output     : "   hi low"
    //       expected (nonprintable as hex) : "000hi low"
    //       actual   (nonprintable as hex) : "   hi low"
    return (0);
}
