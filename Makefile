NAME =			push_swap
CC =			gcc
AR =			ar rcs
CFLAGS =		-Wall -Wextra -Werror -g $(INCLUDES)
INCLUDES=		-I ./src/utils/headers -I /usr/include/c++/11 -I /usr/include/x86_64-linux-gnu/c++/11 -L /usr/lib/gcc/x86_64-linux-gnu/11
LIBFT_DIR =		src/utils/libft
LIBFT =			$(LIBFT_DIR)/libft.a

SRCS =			src/push_swap.c \
				src/commands/push_commands.c \
				src/commands/reverse_commands.c \
				src/commands/rotate_commands.c \
				src/commands/swap_commands.c \
				src/errors/errors.c \
				src/helpers/atoi_modified.c \
				src/helpers/check_duplicates.c \
				src/helpers/check_sorted.c \
				src/helpers/free.c \
				src/helpers/list_traversal.c \
				src/helpers/sort.c \
				src/processors/pre_process.c \
				src/processors/process.c \
				src/processors/stack.c \

OBJS =			$(SRCS:.c=.o)

LIBFT_OBJS =	$(LIBFT_DIR)/*.o

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
				make -C $(LIBFT_DIR)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				rm -f $(NAME)
				rm -f $(LIBFT)
				make fclean -C $(LIBFT_DIR)

re:				fclean all