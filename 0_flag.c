#include "ft_printf.h"

int     int_length(unsigned int n)
{
    int res;

    res = 0;
    while (n > 0)
    {
        res++;
        n /= 10;
    }
    return (res);
}

int     print_int(int n, int zeros)
{
    int res;
    int i;
    int len;

    len = 0;
    res = 0;
    i = 0;
    zeros = (n < 0) ? zeros - 1 : zeros;
    if (n < 0)
    {
        n *= -1;
        res++;
        len += write(1,"-",1);
    }
    i = 0;
    while (i++ < zeros - int_length(n))
        len += write(1,"0",1);
    len += (n != -2147483648) ? ft_d_conversion(n) : write(1,"2147483648",10);
    return (len);
}

int     print_unsigned(unsigned int n, int zeros)
{
    int i;
    int len;

    len = 0;
    i = 0;
    while (i++ < zeros - int_length(n))
        len += write(1,"0",1);
    len += ft_u_conversion(n);
    return (len);
}

int    ft_0_flag(const char **s, va_list vl)
{
    int zeros;

    zeros = 0;
    while (**s == '0' && *s)
        (*s)++;
    zeros = (**s != '*') ? ft_atoi(*s) : va_arg(vl,int);
    if (**s == '*')
        (*s)++;
    while (**s >= '0' && **s <= '9')
        (*s)++;
    if (**s == 'd' || **s == 'i')
        return(print_int(va_arg(vl,int),zeros));
    else if (**s == 'u')
        return(print_unsigned(va_arg(vl,unsigned int),zeros));
    else if (**s == 'x')
        return(print_int(va_arg(vl,int),zeros));
    if (**s == 'd' || **s == 'i')
        return(print_int(va_arg(vl,int),zeros));
    return (0);
}