# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:25:17 by jdomingu          #+#    #+#              #
#    Updated: 2022/08/18 18:48:26 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	minitalk
SERVER_SRC	=	src/server.c
SERVER_OBJ	=	src/server.o
CLIENT_OBJ	=	src/client.o
CLIENT_SRC	=	src/client.c
SERVER		=	server
CLIENT		=	client
LIBFT		=	libft
LIBFT_LIB	=	libft/libft.a
INCLUDE		=	-I include
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT) 

$(SERVER):	$(LIBFT_LIB)
			$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_LIB) $(INCLUDE) -o $(SERVER) 

$(CLIENT):	$(LIBFT_LIB)
			$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_LIB) $(INCLUDE) -o $(CLIENT)

$(LIBFT_LIB):
			@make -C $(LIBFT)

clean:	
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@make clean -C $(LIBFT)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
