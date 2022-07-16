# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:41:50 by shbi              #+#    #+#              #
#    Updated: 2022/07/15 21:03:52 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c list_function.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	push_swap
HEADER		=	push_swap.h
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

ALL			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
%.o			:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@
clean		:
				$(RM) $(OBJS)
fclean		:	clean
				$(RM) $(NAME)
re			:	fclean all
.PHONY		:	all clean fclean re
								