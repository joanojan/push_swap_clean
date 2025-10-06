NAME := push_swap
CC := cc
CFLAGS := -Wall -Werror -Wextra
INCS := -Iincludes

OBJS_DIR := objs

SRCS := \
		src/main.c 							\
		utils/error_exit.c 					\
		utils/ft_atoi_arr_free.c			\
		utils/max.c							\
		utils/min.c							\
		utils/put_str.c						\
		utils/put_char.c					\
		array/arr_is_sorted.c				\
		array/arr_sort.c					\
		array/duplicate_arr.c				\
		stack/create_node.c					\
		stack/create_stack.c				\
		stack/free_stack.c					\
		stack/get_max.c						\
		stack/get_min.c						\
		stack/pop.c							\
		stack/push.c						\
		stack/reverse_rotate.c				\
		stack/rotate.c						\
		stack/swap_stack.c					\
		sorting/is_sorted_stack.c			\
		sorting/sort_stack_five.c			\
		sorting/sort_stack_larger_list.c	\
		sorting/sort_stack_three.c			\
		sorting/sort_stack.c				\
		move_cheapest/assign_indices.c		\
		move_cheapest/get_cheapest_node.c	\
		move_cheapest/move_cheapest.c		\
		move_cheapest/reset_move_plan.c		\
		move_cheapest/set_node_move_plan.c	\
		move_cheapest/set_target.c


OBJS := $(SRCS:.c=.o)
OBJS := $(patsubst %,$(OBJS_DIR)/%,$(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g -O0
debug: re

asan: CFLAGS += -g -O0 -fsanitize=address,undefined
asan: re

# bash splits "3 2 1" into 3 separate arguments, zsh not.
# arg="3 2 1"; ./push_swap $arg won't work in zsh.
# Hence, use bash only or change default behavior with
# 			% setopt SH_WORD_SPLIT
# TESTING:
# Copy paste this commands on the bash shell:
# arg=$(seq 1 100 | shuf | tr "\n" " "); ./push_swap $arg | wc -l
# arg=$(seq 1 100 | shuf | tr "\n" " "); ./push_swap $arg | ./checker_linux $arg
# arg=$(seq 1 500 | shuf | tr "\n" " "); ./push_swap $arg | wc -l
# arg=$(seq 1 500 | shuf | tr "\n" " "); ./push_swap $arg | ./checker_linux $arg
# OR use make test, make test-quick, make test-performance
# ane make valgrind, make valgrind-detailed and make valgrind-quick.

test: $(NAME)
	@echo "=== Push Swap Test Suite ==="
	@echo
	@echo "1. Basic functionality test:"
	@bash -c 'arg="3 2 1" && echo -n "  3 2 1: " && \
	./$(NAME) $$arg | wc -l | tr -d "\n" && echo -n " moves - " && \
	./$(NAME) $$arg | ./checker_linux $$arg'
	@echo
	@echo "2. Small reverse sorted test:"
	@bash -c 'arg="5 4 3 2 1" && echo -n "  5 4 3 2 1: " && \
	./$(NAME) $$arg | wc -l | tr -d "\n" && echo -n " moves - " && \
	./$(NAME) $$arg | ./checker_linux $$arg'
	@echo
	@echo "3. Performance tests with random numbers:"
	@bash -c 'for size in 10 50 100 250 500; do \
		echo -n "  Size $$size: "; \
		arg=$$(seq 1 $$size | shuf | tr "\n" " "); \
		moves=$$(./$(NAME) $$arg | wc -l); \
		result=$$(./$(NAME) $$arg | ./checker_linux $$arg); \
		echo "$$moves moves - $$result"; \
	done'
	@echo
	@echo "=== Test Suite Complete ==="

test-quick: $(NAME)
	@echo "=== Quick Test ==="
	@bash -c 'arg=$$(seq 1 100 | shuf | tr "\n" " ") && \
	echo -n "100 random numbers: " && \
	moves=$$(./$(NAME) $$arg | wc -l) && \
	result=$$(./$(NAME) $$arg | ./checker_linux $$arg) && \
	echo "$$moves moves - $$result"'

test-performance: $(NAME)
	@echo "=== Performance Benchmark ==="
	@bash -c 'echo "Testing multiple runs for consistency:"; \
	for run in 1 2 3; do \
		echo "Run $$run:"; \
		for size in 100 500; do \
			arg=$$(seq 1 $$size | shuf | tr "\n" " "); \
			moves=$$(./$(NAME) $$arg | wc -l); \
			result=$$(./$(NAME) $$arg | ./checker_linux $$arg); \
			echo "  Size $$size: $$moves moves - $$result"; \
		done; \
	done'

valgrind: $(NAME)
	@echo "=== Valgrind Memory Leak Tests ==="
	@echo
	@echo "1. Basic valgrind test (3 elements):"
	@bash -c 'valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-exitcode=1 \
	./$(NAME) 3 2 1 > /dev/null 2>&1 && echo "  \
	✓ No memory leaks detected" || echo "  ✗ Memory issues found"'
	@echo
	@echo "2. Medium size test \
	(50 elem# arg=$(seq 1 100 | shuf | tr "\n" " "); ./push_swap $arg | wc -l
	@bash -c 'arg=$$(seq 1 50 | shuf | tr "\n" " ") && \
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-exitcode=1 \
	./$(NAME) $$arg > /dev/null 2>&1 && echo "  \
	✓ No memory leaks detected" || echo "  ✗ Memory issues found"'
	@echo
	@echo "3. Large size test (100 elements):"
	@bash -c 'arg=$$(seq 1 100 | shuf | tr "\n" " ") && \
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-exitcode=1 \
	./$(NAME) $$arg > /dev/null 2>&1 && echo "  \
	✓ No memory leaks detected" || echo "  ✗ Memory issues found"'
	@echo
	@echo "=== Valgrind Tests Complete ==="

valgrind-detailed: $(NAME)
	@echo "=== Detailed Valgrind Analysis ==="
	@echo
	@echo "Running detailed memory analysis (this may take a moment)..."
	@bash -c 'arg=$$(seq 1 50 | shuf | tr "\n" " ") && \
	echo "Testing with 50 random elements:" && \
	echo "Arguments: $$arg" && \
	echo && \
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose \
	./$(NAME) $$arg'

valgrind-quick: $(NAME)
	@echo "=== Quick Valgrind Check ==="
	@bash -c 'valgrind --leak-check=full --error-exitcode=1 --quiet \
	./$(NAME) 5 4 3 2 1 > /dev/null 2>&1 && \
	echo "✓ Quick valgrind check passed - no memory leaks" || \
	echo "✗ Memory issues detected - run make valgrind-detailed for more info"'

norm:
	norminette $(SRCS) includes/push_swap.h

.PHONY: all clean fclean re debug asan test test-quick test-performance \
valgrind valgrind-detailed valgrind-quick norm
