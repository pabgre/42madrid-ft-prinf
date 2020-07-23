# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:58:38 by psan-gre          #+#    #+#              #
#    Updated: 2019/11/29 12:43:16 by psan-gre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c check_flags.c ft_chrstr.c\
		ft_is_data_type.c print_int.c ft_atoi.c print_flags_functions.c\
		ft_write_case.c print_char.c print_str.c print_hex.c print_uns.c\
		print_mem.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

INCLUDES = ./

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(SRCS) libftprintf.h headers.h
	-@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS)
	-@ar rc $(NAME) $(OBJS)
	-@ranlib $(NAME)
clean:
	-$(RM) $(OBJS)
fclean:		clean
	-$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
