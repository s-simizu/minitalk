# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:22:20 by sshimizu          #+#    #+#              #
#    Updated: 2023/03/14 06:10:38 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SERVER_OBJS = server.o exit_error.o
CLIENT_OBJS = client.o send.o exit_error.o
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
LIB = libft/
LIBFT = libft.a
VPATH = libft

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB)$(LIBFT) -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB)$(LIBFT) -o $@

bonus: all

server.o: server.c libft.h
client.o: client.c libft.h
send.o: exit_error.h
exit_error.o: libft.h

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
