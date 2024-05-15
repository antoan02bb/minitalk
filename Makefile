BROOM=\xF0\x9F\xA7\xB9
CHECK=\xE2\x9C\x94


SOURCES = client.c server.c
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = client_bonus.c server_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

RM = rm -f
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

all: server client
bonus: server_bonus client_bonus

server: server.o libft ft_printf
	@$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf
	@echo "$(CHECK)Compiled Server Successfully$(CHECK)"

client: client.o libft ft_printf
	@$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf
	@echo "$(CHECK)Compiled Client Successfully$(CHECK)"

server_bonus: server_bonus.o libft ft_printf
	@$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf
	@echo "$(CHECK)Compiled Server Bonus Successfully$(CHECK)"

client_bonus: client_bonus.o libft ft_printf
	@$(CC) -o $@ $< -Llibft -lft -Lft_printf -lftprintf
	@echo "$(CHECK)Compiled Client Bonus Successfully$(CHECK)"

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft

ft_printf:
	@make -C ft_printf

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f server client server_bonus client_bonus libft/libft.a ft_printf/libftprintf.a
	@echo "$(BROOM)Cleaned Successfully$(BROOM)"

re: fclean all bonus

.PHONY: all libft ft_printf clean fclean re