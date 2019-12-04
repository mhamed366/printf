#include "ft_printf.h"

int number_of_params(const char *s)
{
    int i;
    i = 0;
    while (*s && *(s + 1))
    {
        printf("%c-%c\n",*s,*(s+1));
        if (*s++ == '%')
            if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' || *s == 'i' || *s == 'u' || *s == 'x' || *s == 'X')
                i++;
    }
    return (i);
}

int ft_printf(const char *sd, ...)
{
    va_list vl;
    va_start(vl,sd);
    while (*sd && *(sd+1))
    {
        if (*sd == '%' && *(sd + 1) == '0')
        {
            sd++;
            //printf("%s","|||||||||||||||||||||||||||");
            ft_0_flag(&sd,vl);
            sd++;
        }
        else if (*sd == '%' && *(sd + 1) == 'c')
        {
            ft_c_conversion(va_arg(vl,int));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == 's')
        {
            ft_s_conversion(va_arg(vl,char*));
            sd+=2;
        }
        else if (*sd == '%' && (*(sd + 1) == 'd' || *(sd + 1) == 'i'))
        {
            ft_d_conversion(va_arg(vl,int));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == 'p')
        {
            write(1,"0x",2);
            ft_p_conversion(va_arg(vl, size_t));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == 'u')
        {
            ft_u_conversion(va_arg(vl, unsigned int));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == 'x')
        {
            ft_x_conversion(va_arg(vl, unsigned int));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == 'X')
        {
            ft_xx_conversion(va_arg(vl, unsigned int));
            sd+=2;
        }
        else if (*sd == '%' && *(sd + 1) == '%')
            sd++;
        else
        {
            write(1,&*sd,1);
            sd++;
        }
    }
    if (*sd)
        write(1,&*sd,1);
    return (0);
}

int main()
{
    //printf("%c\n%c\n",'a','a');
    unsigned int a = -1;
    int kk = 2147483647;
    char c = 'a';
    char d = 'b';
    char *s = " mhamed ";
    const char *s1 = " kchikech ";
    char const *s2 = " midokchi ";
    //char const *s3 = "aa";
    printf("%zu  %p\n",(size_t)s2,s2);
    unsigned int as = 2147483647;
    ft_printf("%c%c%s%s%ssss%d %p  %u %X %% |%020d||%015u|\n",c,d,s,s1,s2,+2147483647,s,a,as,kk,a);
       printf("%c%c%s%s%ssss%d %p  %u %X %% |%020d||%015u|\n",c,d,s,s1,s2,+2147483647,s,a,as,kk,a);
       printf("\nssss%-1ss\n","aaaa");
}