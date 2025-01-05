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
	valgrind -q --leak-check=full ./$(NAME) 218 357 261 362 428 165 243 39 100 200 184 85 193 12 408 55 289 328 203 454 142 409 285 411 127 116 306 83 488 109 335 1 56 273 229 157 387 272 4 236 2 278 129 255 430 19 145 367 6 9 223 472 170 500 79 388 123 390 257 347 262 493 484 265 61 65 275 179 205 302 87 259 400 442 346 353 20 375 351 417 99 125 465 486 288 51 475 206 182 237 199 250 379 153 292 398 435 47 75 234 
#	valgrind -q --leak-check=full ./$(NAME) $(shell shuf -i 1-500 -n 100 | tr '\n' ' ')

#	./$(NAME) 2 1 3 6 5 8
