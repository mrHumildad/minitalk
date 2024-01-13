CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
LIBFT = libft/libft.a
LIBFT_DIR = libft
INCLUDE = -I$(LIBFT_DIR)


all: $(SERVER) $(CLIENT) Makefile

#sin -C no compila
$(LIBFT) : 
	$(MAKE) -C $(LIBFT_DIR)				

$(SERVER): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(SERVER_SRCS) -L$(LIBFT_DIR)  -lft

$(CLIENT): $(CLIENT_SRCS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIR) -lft

