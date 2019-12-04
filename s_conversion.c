#include "ft_printf.h"

void ft_s_conversion(char *s)
{
    write(1,s,strlen(s));
}