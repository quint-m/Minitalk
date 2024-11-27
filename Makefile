# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 20:50:58 by qmennen           #+#    #+#              #
#    Updated: 2024/11/27 20:51:22 by qmennen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): server client

server: server.o libft.a
	$(CC) $(CFLAGS) -o server server.o libft.a

client: client.o libft.a
	$(CC) $(CFLAGS) -o client client.o libft.a

libft.a:
	make -C libft
	mv libft/libft.a libft.a

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client libft.a
	make -C libft fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re
