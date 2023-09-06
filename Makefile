# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 12:11:53 by sbarrage          #+#    #+#              #
#    Updated: 2023/09/06 15:28:47 by sbarrage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	mlx_basics/exit_mlx.c mlx_basics/init_mlx.c mlx_basics/hook_mlx.c\
		render/render_crtl.c render/draw.c\
		main.c\

SRC_DIR = source

SRCS = $(SRC:%=$(SRC_DIR)/%)

OBJ_DIR = object

MORE_ODIR = $(OBJ_DIR)/mlx_basics $(OBJ_DIR)/render

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLXINC = -I ./source/mlx/

MLX = ./source/mlx/libmlx_Linux.a

INCLUDES = -I ./include/ 

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MKDIR = mkdir -p

all:	mlx $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(MORE_ODIR)
	${CC} ${CFLAGS} $(MLXINC) $(INCLUDES) -c $< -o ${<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o} 

$(NAME): ${OBJS}
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -L ./mlx $(MLXINC) $(MLX) -lm -lX11 -lXext  -o $(NAME)
	
mlx:
	@make -sC source/mlx/

mlxclean:
	@make -sC source/mlx/ clean

clean:
	rm -rf ${OBJ_DIR}
	rm -rf $(MORE_ODIR)

fclean:	 mlxclean clean
	rm -f ${NAME}

re: clean fclean all mlxclean
