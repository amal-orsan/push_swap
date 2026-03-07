NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		ft_atoi.c \
		ft_adaptive_algo.c \
		ft_radix.c \
		ft_rotate.c \
		ft_sort.c \
		ft_sort_1.c \
		ft_split.c \
		ft_swap.c \
		ft_free_split.c \
		ft_push.c \
		ft_rev_rotate.c \
		ft_parsing_val.c \
		ft_selectionSort.c \
		ft_stack_build.c \
		ft_make_indexing.c \
		ft_chunk_sort_using_selection_logic.c \
		ft_flags.c \
		ft_bench.c \
		ft_bench_print.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c 
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
