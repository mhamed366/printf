#include "ft_printf.h"

int conver2(int a)
{
    char b;

    b = a + 48;
    if (a == 10)
        write(1,"A",1);
    else if (a == 11)
        write(1,"B",1);
    else if (a == 12)
        write(1,"C",1);
    else if (a == 13)
        write(1,"D",1);
    else if (a == 14)
        write(1,"E",1);
    else if (a == 15)
        write(1,"F",1);
    else 
        write(1,&b,1);
    return (1);
}

int ft_xx_conversion(unsigned int n)
{
    int res;

    res = 0;
    if (n / 16 != 0)
        res += ft_xx_conversion(n/16);
    res += conver2(n % 16);
    return (res);
}