# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 201./ft_printf/11/06 02:40:37 by pvandamm          #+#    #+#              #
#    Updated: 201./ft_printf/11/09 11:03:42 by pvandamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

PATH_SRC = ./libc/

CFLAGS = -Wall -Wextra -Werror -I./includes

OPTION = -c -I$(HEADER)

SRC = ft_bzero.c				\
	  ft_memcpy.c				\
	  ft_memccpy.c				\
	  ft_memmove.c				\
	  ft_memchr.c				\
	  ft_memcmp.c				\
	  ft_strlen.c				\
	  ft_strdup.c				\
	  ft_strcpy.c				\
	  ft_strncpy.c				\
	  ft_strcat.c				\
	  ft_strncat.c				\
	  ft_strlcat.c				\
	  ft_strchr.c				\
	  ft_strrchr.c				\
	  ft_strstr.c				\
	  ft_strnstr.c				\
	  ft_strcmp.c				\
	  ft_strncmp.c				\
	  ft_atoi.c					\
	  ft_isalpha.c				\
	  ft_isdigit.c				\
	  ft_isalnum.c				\
	  ft_isascii.c				\
	  ft_isprint.c				\
	  ft_toupper.c				\
	  ft_tolower.c				\
	  ft_memalloc.c				\
	  ft_memdel.c				\
	  ft_strnew.c				\
	  ft_strdel.c				\
	  ft_strclr.c				\
	  ft_striter.c				\
	  ft_striteri.c				\
	  ft_strmap.c				\
	  ft_strmapi.c				\
	  ft_strequ.c				\
	  ft_strnequ.c				\
	  ft_strsub.c				\
	  ft_strjoin.c				\
	  ft_strtrim.c				\
	  ft_strsplit.c				\
	  ft_itoa.c					\
	  ft_putchar.c				\
	  ft_putstr.c				\
	  ft_putendl.c				\
	  ft_putnbr.c				\
	  ft_putchar_fd.c			\
	  ft_putstr_fd.c			\
	  ft_putendl_fd.c			\
	  ft_putnbr_fd.c 			\
	  ft_abs.c					\
	  ft_strncmp.c				\
	  ft_lstadd.c				\
	  ft_lstdel.c				\
	  ft_lstdelone.c			\
	  ft_lstiter.c				\
	  ft_lstmap.c				\
	  ft_lstnew.c				\
	  ft_swap.c					\
	  ft_is_space.c				\
	  ft_print_words_tables.c	\
	  ft_sqrt.c					\
	  get_next_line.c			\
	  ft_lentoc.c				\
	  ./ft_printf/padding/print_d_option.c	\
	  ./ft_printf/padding/print_x_option.c	\
	  ./ft_printf/padding/print_p_option.c	\
	  ./ft_printf/padding/print_u_option.c	\
	  ./ft_printf/padding/print_o_option.c	\
	  ./ft_printf/padding/print_s_option.c	\
	  ./ft_printf/padding/print_bx_option.c	\
	  ./ft_printf/srcs/ft_printf.c 			\
	  ./ft_printf/srcs/fill_struct.c		\
	  ./ft_printf/srcs/print_arg.c			\
	  ./ft_printf/srcs/print_p.c			\
	  ./ft_printf/srcs/print_o.c			\
	  ./ft_printf/srcs/print_c.c			\
	  ./ft_printf/srcs/print_x.c			\
	  ./ft_printf/srcs/print_s.c			\
	  ./ft_printf/srcs/print_bx.c			\
	  ./ft_printf/srcs/print_d.c			\
	  ./ft_printf/srcs/print_u.c			\
	  ./ft_printf/srcs/print_nb.c			\
	  ./ft_printf/srcs/print_percent.c		\
	  ./ft_printf/srcs/utils.c				\
	  ./ft_printf/srcs/get_arg.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mlibft is ready\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[33mall .o files are removed\033[0m"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
