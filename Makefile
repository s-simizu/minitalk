# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:22:20 by sshimizu          #+#    #+#              #
#    Updated: 2023/03/01 18:59:44 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
OBJS = server.o client.o send.o exit_error.o
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
LIB = libft/
LIBFT = libft.a
VPATH = libft

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.o exit_error.o $(LIB)$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): client.o send.o exit_error.o $(LIB)$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

server.o: server.c libft.h
client.o: client.c libft.h
send.o: exit_error.h
exit_error.o: libft.h

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
