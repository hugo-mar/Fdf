# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:39:20 by hugo-mar          #+#    #+#              #
#    Updated: 2024/10/01 20:04:10 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ARCHIVE = fdf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

SRCS = fdf.c map_utils1.c map_utils2.c map_utils3.c \
		twistft.c twistsplit.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
