# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2021/09/20 21:04:59 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= client
NAME2	= server
LIBFT	= libft.a

LIBFT_PATH		= ./libraries/libft/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.c

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	minitalk.h	\

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Wextra  -g
LIBRARIES	= -L$(LIBFT_PATH) -lft
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

all:		$(NAME)

$(NAME1):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.c $(HEADERS)
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
			@echo making libft...
			@echo --------------------------
			@make -sC $(LIBFT_PATH)
			@echo done!
			@echo --------------------------

clean:
			@make -sC $(LIBFT_PATH) fclean
			@make -sC $(LIBFT_PATH) clean
			@rm -f $(OBJS)
			echo cleaned!
fclean:		clean
			@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re