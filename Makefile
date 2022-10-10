# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 02:43:33 by joacaeta          #+#    #+#              #
#    Updated: 2022/10/09 20:06:05 by joacaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Wextra -Werror -g -fsanitize=address
LIBRARIES := -Llibft -lft
INCLUDE_DIRS := libft \
				src \
				inc \
				mains \
				.
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))
NAME := push_swap
NAME_B := checker
SRCS := $(wildcard src/*.c)
MAIN := $(wildcard mains/mandatory.c)
MAIN_B := $(wildcard mains/bonus.c)
OBJS := $(SRCS:.c=.o) $(MAIN:.c=.o)
OBJS_B := $(SRCS:.c=.o) $(MAIN_B:.c=.o)

all: libft $(NAME)

libft:
	make -C libft/

bonus: libft $(NAME_B)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ $(LIBRARIES) -o $@ $(INCLUDES)

$(NAME_B) : $(OBJS_B)
	$(CC) $(FLAGS) $^ $(LIBRARIES) -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(OBJS_B)
	$(MAKE) -C libft/ clean

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_B)
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: libft minilibx all bonus clean fclean re bonus
