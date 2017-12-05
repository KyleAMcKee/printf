#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmckee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:55:28 by kmckee            #+#    #+#              #
#    Updated: 2017/12/04 21:19:47 by kmckee           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a
SRCDIR		=	srcs/
INCDIR		= 	includes/
OBJDIR		=	temp/
LIBFT		=	libft/
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

SOURCES		=	ft_printf.c \
				check_flags.c check_length.c \
				type_handler.c check_width.c\
				arg_conversion.c \
				char_format.c string_format.c \
				int_format.c hex_format.c \
				octal_format.c unsigned_format.c \
				percent_format.c width_format.c \
				pointer_format.c wchar_format.c \
				print_max.c undef_format.c

SRCS		=	$(addprefix $(SRCDIR), $(SOURCES))
OBJS		=	$(addprefix $(OBJDIR), $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\x1b[31mCreating Library...\x1b[0m"
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\x1b[32mDone\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p temp
	$(CC) $(FLAGS) -I $(INCDIR) -c -o $@ $<

test:
	make re
	$(CC) $(FLAGS) -o test main.c print_status.c $(NAME)
	make clean
	./test

undef:
	make re
	$(CC) -o undef main.c print_status.c $(NAME)
	make clean

clean:
	@echo "\x1b[31mRemoving object files...\x1b[0m"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@echo "\x1b[32mDone\x1b[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
