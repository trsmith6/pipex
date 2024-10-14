# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 09:44:48 by trsmith           #+#    #+#              #
#    Updated: 2024/07/04 09:45:05 by trsmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c

OBJS	=	$(SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = gnl.a

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

RM = rm -f

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.cc
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	$(RM) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
