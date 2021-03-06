# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/05/19 18:01:43 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
END = \033[0m
##################################_COMPILATION_#################################
CC = clang
FLAG = -O3 -Wall -Wextra -Werror
LFT = ./libft/libft.a
LSDL = -L ./libsdl/ -lSDL2
INCLUDE = -I ./includes/wolf.h -I ./libft/includes/ -I ./includes/SDL2/
OBJS = ./main.o \
	   ./window.o \
	   ./init.o \
	   ./wolf.o \
	   ./color.o \
	   ./keyboard.o \
	   ./sound.o \
	   ./map.o \
	   ./weapon.o \

NAME = wolf3d
FRAMEWORK = -framework OpenGL
##################################_CHANGE_PATH_#################################
SDL2DYLIB = ./libsdl/libSDL2-2.0.0.dylib
SDL2_image = ./libsdl/SDL2_image
##################################_RELINK_MODIFY_.h#############################
RELINK_H = ./includes/wolf.h

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREY)Compiling libft.a ...$(GREY)"
	@make -s -C ./libft/
	@printf "                   [$(GREEN)Success$(GREY)]\n"
	@printf "Compiling .o ..."
	@printf "                        [$(GREEN)Success$(GREY)]\n"
	@printf "Compiling wolf3d ..."
	@$(CC) $(FLAG) $(LFT) $(LSDL) $(INCLUDE) $(OBJS) -o $(NAME) $(FRAMEWORK)\
		$(SDL2_image)
	@printf "                    [$(GREEN)Success$(GREY)]\n$(END)"
	@install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib $(SDL2DYLIB)\
		$(NAME)
	@install_name_tool -change \
		@rpath/SDL2_image.framework/Versions/A/SDL2_image $(SDL2_image) $(NAME)
	@install_name_tool -change lib/libsdl/libSDL2-2.0.0.dylib $(SDL2DYLIB)\
		$(SDL2_image)

%.o : %.c ${RELINK_H}
	@$(CC) -c $(FLAG) $< -o $@

clean:
	@printf "$(GREY)deleting all .o ...$(END)"
	@rm -f $(OBJS)
	@printf " [$(GREEN)Success$(GREY)]\n$(END)"

fclean:
	@printf "$(GREY)Deleting libft.a, all .o and Wolf3d ...$(END)"
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/
	@printf " $(GREY)[$(GREEN)Success$(GREY)]\n$(END)"

re: fclean all
