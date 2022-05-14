NAME	:=	so_long

CSAN	:=	-fsanitize=address -g3

CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror $(CSAN)
MLX_FLAGS	:=	-framework OpenGl -framework AppKit

DIR_SRCS	:=	sources
DIR_OBJS	:=	.objs
DIR_INCS	:=	includes

DIR_LIBFT	:=	libft
DIR_MLX	:=	mlx

LST_SRCS	:=	main.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	so_long.h

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT	:=	$(DIR_LIBFT)/libft.a
AR_MLX	:=	$(DIR_MLX)/libmlx.a

all	:	make_libft	$(NAME)

$(NAME)	:	$(AR_LIBFT) $(AR_MLX) $(OBJS)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@

$(DIR_OBJS)/%.o	:	$(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
					$(CC) $(CFLAGS) -I $(DIR_INCS) -Imlx -c $< -o $@

$(AR_LIBFT)	:
				$(MAKE) -C $(DIR_LIBFT)

$(AR_MLX)	:
				$(MAKE) -C $(DIR_MLX)

$(DIR_OBJS)	:
				mkdir -p $(DIR_OBJS)

make_libft	:
				$(MAKE) -C $(DIR_LIBFT)

clean	:
			rm -rf $(OBJS)
			$(MAKE) clean -C $(DIR_LIBFT)

fclean	:	clean
			rm -rf $(NAME)
			$(MAKE) fclean -C $(DIR_LIBFT)

re	:
		fclean
		all

.PHONY	:	all make_libft clean fclean re
