BROOM=\xF0\x9F\xA7\xB9
CHECK=\xE2\x9C\x94


SOURCES = client.c server.c
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = client_bonus.c server_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc 
CFLAGS = -Wall -Wextra -Werror

all: server client
bonus: server_bonus client_bonus

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft
	@echo "$(CHECK)Compiled Server Successfully$(CHECK)"

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft
	@echo "$(CHECK)Compiled Client Successfully$(CHECK)"

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft

ft_printf:
	@make -C ft_printf

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f server client libft/libft.a
	@echo "$(BROOM)Cleaned Successfully$(BROOM)"

re: fclean all bonus

.PHONY: all libft clean fclean re