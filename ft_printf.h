#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void    ft_c_conversion(char c);
int	ft_d_conversion(int n);
void    hex_conver(unsigned int n);
void    ft_s_conversion(char *s);
int    ft_u_conversion(unsigned int n);
void    ft_p_conversion(size_t n);
int    conver(int a);
int    ft_x_conversion(unsigned int a);
int    ft_xx_conversion(unsigned int a);
int		ft_atoi(const char *str);
int    ft_0_flag(const char **s, va_list vl);

#endif