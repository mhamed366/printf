#include "ft_printf.h"

void    ft_p_conversion(size_t n)
{
    if (n / 16 != 0)
        ft_p_conversion(n/(size_t)16);
    conver(n % 16);
}