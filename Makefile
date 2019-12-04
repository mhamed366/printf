NAME = libft.a
SRC = c_conversion.c \
d_conversion.c \
x_conversion.c \
printf.c \
s_conversion.c \
u_conversion.c \
p_conversion.c \
xx_conversion.c \
0_flag.c \
atoi.c
OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all