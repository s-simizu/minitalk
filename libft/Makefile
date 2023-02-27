# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 00:18:44 by sshimizu          #+#    #+#              #
#    Updated: 2023/02/24 04:22:04 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_atoi.c               ft_bzero.c              ft_calloc.c \
ft_isalnum.c            ft_isalpha.c            ft_isascii.c \
ft_isdigit.c            ft_isprint.c            ft_itoa.c \
ft_memchr.c             ft_memcmp.c             ft_memcpy.c \
ft_memmove.c            ft_memset.c             ft_putchar_fd.c \
ft_putendl_fd.c         ft_putnbr_fd.c          ft_putstr_fd.c \
ft_split.c              ft_strchr.c             ft_strdup.c \
ft_striteri.c           ft_strjoin.c            ft_strlcat.c \
ft_strlcpy.c            ft_strlen.c             ft_strmapi.c \
ft_strncmp.c            ft_strnstr.c            ft_strrchr.c \
ft_strtrim.c            ft_substr.c             ft_tolower.c \
ft_toupper.c            ft_printf.c             format.c \
format2.c				ft_free.c				ft_swap.c \
ft_bubble_sort.c		ft_min.c				ft_max.c \
ft_search_index.c       ft_isspace.c            get_next_line.c

B_SRCS := ft_lstadd_back.c        ft_lstadd_front.c       ft_lstclear.c \
ft_lstdelone.c          ft_lstiter.c            ft_lstlast.c \
ft_lstmap.c             ft_lstnew.c             ft_lstsize.c

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
B_OBJS := $(B_SRCS:.c=.o)
OBJS += $(B_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
