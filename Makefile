CC = cc
# CFLAGS = -Wall -Wextra -Werror
NAME = so_long
ARCHIVE = ar -rc
MINILIBX = -lmlx -framework OpenGL -framework AppKit

SRC = get_next_line.c gnl_utils.c libft_utils.c so_long.c
OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ) so_long.h
	$(ARCHIVE) so_long.a $(OBJ)
	$(CC) so_long.o -o so_long -L. so_long.a $(MINILIBX)

$(OBJ) : $(SRC)
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all

# NAME = so_long.a

# FLAGS= -Wall -Wextra -Werror

# SRCS= get_next_line.c gnl_utils.c libft_utils.c so_long.c

# SRCS_BONUS= get_next_line.c gnl_utils.c libft_utils.c so_long_bonus.c

# OBJS= $(SRCS:.c=.o)

# OBJS_BONUS= $(SRCS_BONUS:.c=.o)

# all: $(NAME)

# %.o: %.c so_long.h so_long_bonus.h
# 	cc -c $(FLAGS) $<

# $(NAME): $(OBJS)
# 	@ar -r $(NAME) $(OBJS)

# bonus: $(OBJS_BONUS)
# 	@ar -r $(NAME) $(OBJS_BONUS)

# clean:
# 	@rm -f $(OBJS) $(OBJS_BONUS)

# fclean:clean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: bonus all clean fclean re