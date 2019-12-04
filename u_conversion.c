#include "ft_printf.h"

int    ft_u_conversion(unsigned int n)
{
    unsigned int res;
	int len;
    char r;

	len = 0;
	res = (size_t)n;
	if (res >= 10)
		len += ft_u_conversion(res / 10);
    r = (res % 10) + 48;
	len += write(1,&r, 1);
	return (len);
}