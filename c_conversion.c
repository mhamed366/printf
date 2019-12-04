#include "ft_printf.h"

void ft_c_conversion(char c)
{
    write(1,&c,1);
}