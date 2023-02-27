# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:22:20 by sshimizu          #+#    #+#              #
#    Updated: 2023/02/28 00:04:55 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
LIB = libft/
LIBFT = libft.a
VPATH = libft

all: $(SERVER) $(CLIENT)

$(SERVER): server.o exit_error.o $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): client.o exit_error.o $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

server.o: server.c libft.h

client.o: client.c libft.h

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)
	rm -f server.o

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
