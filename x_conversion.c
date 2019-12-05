#include "ft_printf.h"

int conver(int a)
{
    int res;
    char b;

    res = 0;
    b  = a + 48;
    if (a == 10)
        res += write(1,"a",1);
    else if (a == 11)
        res += write(1,"b",1);
    else if (a == 12)
        res += write(1,"c",1);
    else if (a == 13)
        res += write(1,"d",1);
    else if (a == 14)
        res += write(1,"e",1);
    else if (a == 15)
        res += write(1,"f",1);
    else 
        res += write(1,&b,1);
    return (res);
}

int ft_x_len(unsigned int n)
{
    int res;

    res = 0;
    if (n / 16 != 0)
        res += ft_x_len(n/16);
    res += 1;
    return (res);
}

int ft_x_conversion(unsigned int n)
{
    int res;

    res = 0;
    if (n / 16 != 0)
        res += ft_x_conversion(n/16);
    res += conver(n % 16);
    return (res);
}