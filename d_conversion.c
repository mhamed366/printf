#include "ft_printf.h"

int	ft_d_conversion(int n)
{
	size_t res;
    char r;
	int len;

	len = 0;
	if (n < 0)
	{
		len += write(1,"-", 1);
		res = (size_t)n * -1;
	}
	else
		res = (size_t)n;
	if (res >= 10)
		ft_d_conversion(res / 10);
    r = (res % 10) + 48;
	len += write(1,&r, 1);
	return (len);
}