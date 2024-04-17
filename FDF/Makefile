# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 16:23:32 by memahote          #+#    #+#              #
#    Updated: 2023/02/26 16:23:32 by memahote         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

INC			=	fdf.h 
INC_DIR		=	./include/

HEADERS		= $(addprefix $(INC_DIR), $(INC))

SRC			=	fdf.c 			\
				read_file.c		\
				draw.c 			\
				init.c clean.c	\
				deal_key.c		\
				utils.c
			
					


LIBFT_DIR	=	libft/
LIBFT_A		=	$(LIBFT_DIR)libft.a

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)

CC			=	gcc
CC_FLAGS	=	-Wextra -Werror -Wall -g3

MLX_DIR	=	mlx_linux/
MLX_A	=	$(MLX_DIR)libmlx.a
MLX_FLAG = -L $(MLXDIR) -lm  -lXext -lX11


Pink=\033[1;38;5;205m
NONE = \033[39m


ascii=      ███████╗██████╗ ███████╗ \n\
			██╔════╝██╔══██╗██╔════╝ \n\
			█████╗  ██║  ██║█████╗   \n\
			██╔══╝  ██║  ██║██╔══╝   \n\
			██║     ██████╔╝██║      \n\
			╚═╝     ╚═════╝ ╚═╝      \n

all: build_libft $(NAME)
	@echo -e "\033[31mCompiling \033[1mis done !\033[0;31m $(NONE)"

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A) $(LIBFT_DIR)
		@echo -e "\033[31mCompiling \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
		$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) $(MLX_A) $(MLX_FLAG) -o $@ -lm -s
	

build_libft: $(LIBFT_DIR)
		@echo -e " $(Pink)$(ascii)"
		$(MAKE) -s -C $(LIBFT_DIR) 

$(MLX_A): $(MLX_DIR)
		$(MAKE) -s -C $(MLX_DIR) 

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p $(@D) 
		$(CC) $(CC_FLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -I$(MLX_DIR) -c $< -o $@

clean:
		@echo -e "\033[31mRemoving \033[1mobjects files\033[0;31m...\033[0m $(NONE)"
		$(MAKE) clean -s -C $(LIBFT_DIR)
		$(MAKE) clean -s -C $(MLX_DIR)
		rm -rf $(OBJ_DIR) 

fclean: clean
		@echo -e "\033[31mAnd \033[1mexecutable file !\033[0;31m\033[0m $(NONE)"
		rm -rf $(NAME)
		$(MAKE) fclean -s -C $(LIBFT_DIR) 
		

re: fclean all

.SILENT : clean all fclean $(NAME) re $(SRCS:.c=.o)  build_libft $(OBJ) $(MLX_A)

.PHONY: all clean fclean re build_libft
