CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = push_swap.c stack_functions.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
