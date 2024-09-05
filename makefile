# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 11:36:05 by ddifalla          #+#    #+#              #
#    Updated: 2024/09/05 18:05:48 by tmazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC            =    gcc
CFLAGS        =    -Wall -Wextra -Werror

SERVER        =    ft_server/ft_server.c
CLIENT        =    ft_client/ft_client.c
HELPERS       =    ft_helpers.c

SERVER_SRC    =    $(SERVER)
SERVER_OBJS   =    $(SERVER_SRC:.c=.o)

CLIENT_SRC    =    $(CLIENT)
CLIENT_OBJS   =    $(CLIENT_SRC:.c=.o)

HELPERS_SRC   =    $(HELPERS)
HELPERS_OBJS  =    $(HELPERS_SRC:.c=.o)

OBJS		=	$(SERVER_OBJS) $(CLIENT_OBJS) $(HELPERS_OBJS)

all: server client

server: $(SERVER_OBJS) $(HELPERS_OBJS)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJS) $(HELPERS_OBJS)

client: $(CLIENT_OBJS) $(HELPERS_OBJS)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJS) $(HELPERS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re