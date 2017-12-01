#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmckee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:55:28 by kmckee            #+#    #+#              #
#    Updated: 2017/11/30 14:41:39 by kmckee           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a
SRC			=	srcs/
INC			= 	includes/
FILES		=	ft_printf \
				check_flags check_length \
				type_handler \
				arg_conversion \
				char_format string_format \
				int_format hex_format \
				octal_format unsigned_format \
				percent_format width_format \
				pointer_format \
				print_max \

SRC_FILES	= 	$(addprefix $(SRC), $(FILES))
C_FILES 	= 	$(addsuffix .c, $(SRC_FILES))
O_FILES		= 	$(addsuffix .o, $(SRC_FILES))

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
LIBFT		=	libft/libft.a

all: $(NAME)

$(NAME):
	make all -C libft
	$(CC) $(FLAGS) -c $(C_FILES) -I $(INC)
	mv *.o srcs/
	ar rcs $(NAME) $(O_FILES)
	rm srcs/*.o
	ar -x $(LIBFT)
	ar -x $(NAME)
	ar rcs $(NAME) *.o

test:
	make re
	$(CC) $(FLAGS) -o test main.c print_status.c $(NAME)
	make clean

undef:
	make re
	$(CC) -o undef main.c print_status.c $(NAME)
	make clean

clean:
	make clean -C libft
	rm *.o
	rm _*

fclean:
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
