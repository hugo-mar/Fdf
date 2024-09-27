# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:39:20 by hugo-mar          #+#    #+#              #
#    Updated: 2024/09/27 19:21:10 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ARCHIVE = fdf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

SRCS = fdf.c twistsplit.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $(ARCHIVE) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS) $(BONUS_OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re