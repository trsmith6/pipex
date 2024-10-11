# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 15:24:05 by trsmith           #+#    #+#              #
#    Updated: 2024/10/09 13:54:10 by trsmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	pipex.c \
		family.c \
		
COMPILER = cc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@cd main-libs && make --silent
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) ./main-libs/libs.a
clean:
	@cd main-libs && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re