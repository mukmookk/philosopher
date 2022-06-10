# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 00:28:22 by youngmki          #+#    #+#              #
#    Updated: 2022/03/17 08:56:10 by youngmki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror    

SRCS = main.c	\
		lib_utils.c \
		philo_utils.c \
		init.c \

OBJS = $(SRCS:.c=.o)

EXECUTABLE = philosopher

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE)

%.o: %.c
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(EXECUTABLE)

re: fclean all

start:
		 ./$(EXECUTABLE)

.PHONY: all bonus clean fclean re start