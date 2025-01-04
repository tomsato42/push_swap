CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = .c
SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#	valgrind -q --leak-check=full ./$(NAME) 10 1 13 6 12 3 8 9 5 2 11 7 4 14 15
	valgrind -q --leak-check=full ./$(NAME) $(shell shuf -i 1-500 -n 500 | tr '\n' ' ')

#	./$(NAME) 2 1 3 6 5 8
