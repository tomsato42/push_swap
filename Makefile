CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = apply_best_move.c arr_isdup.c arr_issorted.c calc_score.c \
	find_best_move.c ft_atoi.c ft_strlen.c greedy_sort.c \
	handle_small_list.c is_input_enabled.c list_add_tail.c list_free.c \
	list_init.c list_push.c list_rotate.c list_swap.c \
	merge_sort.c move_head_to_min_value.c parse_input.c sort_small_list.c \
	push_swap.c
OBJS = $(SRCS:.c=.o)

CHECKER_NAME = checker
CHECKER_SRCS = apply_best_move.c arr_isdup.c arr_issorted.c calc_score.c \
	find_best_move.c ft_atoi.c ft_strlen.c greedy_sort.c \
	handle_small_list.c is_input_enabled.c list_add_tail.c list_free.c \
	list_init.c list_push.c list_rotate.c list_swap.c \
	merge_sort.c move_head_to_min_value.c parse_input.c sort_small_list.c \
	ft_strncmp.c checker.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)

re: fclean all

RANGE_START = 1
RANGE_END = 500
NUM_COUNT = 100
RANDOM_NUMBERS = $(shell shuf -i $(RANGE_START)-$(RANGE_END) -n $(NUM_COUNT) | tr '\n' ' ')

test: $(NAME)
	valgrind -q --leak-check=full ./$(NAME) 218 357 261 362 428 165 243 39 100 200 184 85 193 12 408 55 289 328 203 454 142 409 285 411 127 116 306 83 488 109 335 1 56 273 229 157 387 272 4 236 2 278 129 255 430 19 145 367 6 9 223 472 170 500 79 388 123 390 257 347 262 493 484 265 61 65 275 179 205 302 87 259 400 442 346 353 20 375 351 417 99 125 465 486 288 51 475 206 182 237 199 250 379 153 292 398 435 47 75 234 
#	valgrind -q --leak-check=full ./$(NAME) $(RANDOM_NUMBERS)

#	./$(NAME) 2 1 3 6 5 8

test2: $(NAME) $(CHECKER_NAME)
	valgrind -q --leak-check=full ./$(NAME) $(RANDOM_NUMBERS) | ./$(CHECKER_NAME) $(RANDOM_NUMBERS)