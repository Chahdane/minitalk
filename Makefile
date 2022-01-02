
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all:
	$(CC) $(CFLAGS) server.c -o server
	$(CC) $(CFLAGS) client.c -o client

clean:
	$(RM) server
	$(RM) client

re: clean all