# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:22:20 by sshimizu          #+#    #+#              #
#    Updated: 2023/04/08 23:42:44 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SERVER_SRCS = server.c exit_error.c bits.c
CLIENT_SRCS = client.c send.c exit_error.c bits.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iinclude
LIB = libft/
LIBFT = libft.a
VPATH = libft src include

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB)$(LIBFT) -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB)$(LIBFT) -o $@

bonus: all

server.o: libft.h info.h bits.h
client.o: libft.h
send.o: exit.h bits.h
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
