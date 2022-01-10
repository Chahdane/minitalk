SRC = utls/*.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: server client

server:
	@$(CC) $(CFLAGS) server.c $(SRC) -o server
	@echo "\033[92mSERVER GOT CREATED\033[0m"
client:
	@$(CC) $(CFLAGS) client.c $(SRC) -o client
	@echo "\033[92mCLIENT GOT CREATED\033[0m"

clean:
	@$(RM) server
	@$(RM) client

fclean: clean

re: clean all
