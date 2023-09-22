# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stan <stan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 12:11:53 by sbarrage          #+#    #+#              #
#    Updated: 2023/09/13 01:12:05 by stan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	mlx_basics/exit_mlx.c mlx_basics/init_mlx.c mlx_basics/hook_mlx.c\
		render/render_crtl.c render/draw.c render/first_draft.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c\
		main.c\

SRC_DIR = source

SRCS = $(SRC:%=$(SRC_DIR)/%)

OBJ_DIR = object

MORE_ODIR = $(OBJ_DIR)/mlx_basics $(OBJ_DIR)/render $(OBJ_DIR)/gnl

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLXINC = -I ./source/mlx/

MLX = ./source/mlx/libmlx_Linux.a

LIBFTINC = -I ./source/Libft/

LIBFT = ./source/Libft/libft.a

INCLUDES = -I ./include/

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MKDIR = mkdir -p

all:	mlx $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(MORE_ODIR)
	${CC} ${CFLAGS} $(MLXINC) $(LIBFTINC) $(INCLUDES) -c $< -o ${<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

$(NAME): ${OBJS}
	make -C ./source/Libft
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -L ./mlx $(LIBFTINC) $(LIBFT) $(MLXINC) $(MLX) -lm -lX11 -lXext  -o $(NAME)

mlx:
	@make -sC source/mlx/

mlxclean:
	@make -sC source/mlx/ clean

clean:
	rm -rf ${OBJ_DIR}
	rm -rf $(MORE_ODIR)

fclean:	 mlxclean clean
	@make fclean -C ./source/Libft
	rm -f ${NAME}

re: clean fclean all mlxclean
