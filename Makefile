# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 12:11:53 by sbarrage          #+#    #+#              #
#    Updated: 2023/10/02 14:57:13 by sbarrage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	mlx_basics/exit_mlx.c mlx_basics/init_mlx.c mlx_basics/hook_mlx.c\
		render/render_crtl.c render/draw.c render/first_draft.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c\
		parsing/extractor.c parsing/parse.c parsing/tester.c parsing/checks.c\
		parsing/extractor_2.c parsing/checks_2.c\
		main.c error.c\

SRC_DIR = source

SRCS = $(SRC:%=$(SRC_DIR)/%)

OBJ_DIR = object

MORE_ODIR = $(OBJ_DIR)/mlx_basics $(OBJ_DIR)/render $(OBJ_DIR)/gnl $(OBJ_DIR)/parsing

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLXINC = -I ./source/mlx/

MLX = ./source/mlx/libmlx_Linux.a

LIBFTINC = -I ./source/Libft/

LIBFT = ./source/Libft/libft.a

INCLUDES = -I ./include/

CC	= gcc

CFLAGS = -Wall -Wextra -Werror -g

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
