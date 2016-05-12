# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/05/12 20:53:57 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[48;5;196m
SKIN = \033[0m\033[48;5;223m
BROWN = \033[48;5;88m
BLUE = \033[48;5;21m
YELLOW = \033[48;5;226m
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
END = \033[0m

NAME = Wolf3d
FLAG = -Ofast
FRAMEWORK = -framework OpenGL -framework AppKit
OBJS = ./main.o \
	   ./init.o \

INCLUDE = $(wildcard ./includes/Wolf3d.h ./includes/keyboard.h)

LFT = -L./libft/ -lft
LMLX = -L./minilibx_macos/ -lmlx

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREY)Compiling libft.a ...$(GREY)"
	@make -s -C ./libft/
	@printf "                   [$(GREEN)Success$(GREY)]\n"
	@printf "Compiling mlx.a ..."
	@make -s -C ./minilibx_macos/
	@printf "                     [$(GREEN)Success$(GREY)]\n"
	@printf "Compiling .o ..."
	@printf "                        [$(GREEN)Success$(GREY)]\n"
	@printf "Compiling Wolf3d ..."
	@gcc $(FLAG) -o $(NAME) $(OBJS) $(LMLX) $(LFT) $(FRAMEWORK)
	@printf "                    [$(GREEN)Success$(GREY)]\n$(END)"

%.o : %.c ${INCLUDE}
		@gcc -c $(FLAG) $< -o $@

clean:
	@printf "$(GREY)deleting all .o ..."
	@rm -f $(OBJS)
	@printf " [$(GREEN)Success$(GREY)]\n$(END)"

fclean:
	@printf "$(GREY)Deleting libft.a, all .o and Wolf3d ..."
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/
	@make -s clean -C ./minilibx_macos/
	@printf " [$(GREEN)Success$(GREY)]\n$(END)"

re: fclean all
