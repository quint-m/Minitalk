
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

LIBFT_INC_PATH = libft/include

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Colors
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RED = \033[31m
RESET = \033[0m

all: $(NAME)
	@echo "$(GREEN)✅ Building all targets...$(RESET)"

$(NAME): server client

server: server.o libft.a
	@echo "$(YELLOW)🚀 Compiling server...$(RESET)"
	$(CC) $(CFLAGS) -o server server.o libft.a
	@echo "$(GREEN)✅ Server built!$(RESET)"

client: client.o libft.a
	@echo "$(YELLOW)🚀 Compiling client...$(RESET)"
	$(CC) $(CFLAGS) -o client client.o libft.a
	@echo "$(GREEN)✅ Client built!$(RESET)"

libft.a:
	@echo "$(BLUE)📦 Building libft...$(RESET)"
	make -C libft > /dev/null 2>&1
	mv libft/libft.a libft.a
	@echo "$(GREEN)✅ libft.a ready!$(RESET)"

server.o: server.c libft.a
	@echo "$(BLUE)🔧 Compiling server.c...$(RESET)"
	$(CC) $(CFLAGS) -I $(LIBFT_INC_PATH) -c server.c

client.o: client.c libft.a
	@echo "$(BLUE)🔧 Compiling client.c...$(RESET)"
	$(CC) $(CFLAGS) -I $(LIBFT_INC_PATH) -c client.c

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	@echo "$(RED)🧹 Removing all binaries and libft.a...$(RESET)"
	rm -f server client libft.a
	make -C libft fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re
