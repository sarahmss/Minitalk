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

CLIENT	= client
SERVER	= server
LIBFT	= libft.a

LIBFT_PATH		= ./libraries/libft/
SRC_PATH_S		= ./source/source_s/
SRC_PATH_C		= ./source/source_c/
INCLUDES_PATH	= ./includes/
OBJS_PATH_S		= ./objects/objects_s/
OBJS_PATH_C		= ./objects/objects_c/


SRCS_FILES_S =	server.c
SRCS_FILES_C =	client.c

SRCS_S = $(addprefix $(SRC_PATH_S), $(SRCS_FILES_S))
SRCS_C = $(addprefix $(SRC_PATH_C), $(SRCS_FILES_C))

OBJS_FILES_C	= $(patsubst %.c, %.o, $(SRCS_FILES_C))
OBJS_FILES_S	= $(patsubst %.c, %.o, $(SRCS_FILES_S))
OBJS_S = $(addprefix $(OBJS_PATH_S), $(OBJS_FILES_S))
OBJS_C = $(addprefix $(OBJS_PATH_C), $(OBJS_FILES_C))

HEADER_FILES	=	minitalk.h	\

HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Wextra  -g
LIBRARIES	= -L$(LIBFT_PATH) -lft
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS_C) $(LIBFT)
			$(CC) $(OBJS_C) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(CLIENT)
			@echo client ready!
			@echo --------------------------
			
$(SERVER):	$(OBJS_S) $(LIBFT)
			$(CC) $(OBJS_S) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(SERVER)
			@echo server ready!
			@echo --------------------------

$(OBJS_PATH_S)%.o : $(SRC_PATH_S)%.c $(HEADERS)
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
$(OBJS_PATH_C)%.o : $(SRC_PATH_C)%.c $(HEADERS)
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
			@rm -f $(OBJS_S)
			@rm -f $(OBJS_C)
			echo cleaned!
fclean:		clean
			@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
