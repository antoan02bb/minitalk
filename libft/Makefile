NAME = libft.a

SRCS =	ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_isdigit.c ft_tolower.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_toupper.c \
		ft_strcmp.c ft_strchr.c ft_strrchr.c ft_memmove.c \
		ft_atoi.c ft_strlcat.c ft_memchr.c ft_calloc.c ft_strtrim.c \
		ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_strjoin.c ft_strdup.c \
		ft_strnstr.c ft_memcmp.c ft_strncmp.c ft_putendl_fd.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c \
		ft_print_hex.c ft_print_ptr.c ft_printstr.c ft_putchar.c ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_unsigned.c

OBJ = $(SRCS:.c=.o)

BONUS =  ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BONUS_OBJ = $(BONUS:.c=.o)

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJ) $(OBJ)
	ar rc $(NAME) $(BONUS_OBJ) $(OBJ) 

.PHONY: all clean fclean re