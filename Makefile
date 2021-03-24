# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasnivala <joonasnivala@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2021/03/24 13:46:41 by joonasnival      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
S = srcs
O = objs

LIBFT_WIN = libft\libft.a
LIBFT_LINUX = libft/libft.a

WIN_INCLUDE_PATHS = -ISDL2\include\SDL2 -ISDL2_mixer_win\include\SDL2 -Ilibft
LINUX_INCLUDE_PATHS = -I/SDL2/include/SDL2/ -I/usr/include/SDL2 -Ilibft

WIN_LIBRARY_PATHS = -LSDL2\lib -LSDL2_mixer_win\lib -Llibft
LINUX_LIBRARY_PATHS = -L/lib/ -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -Llibft

WIN_COMPILER_FLAGS = -w
LINUX_COMPILER_FLAGS = -Wall -Wextra

WIN_LINK_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_ttf -lft
LINUX_LINK_FLAGS = -lSDL2 -lSDL2main -lSDL2_mixer -lSDL2_ttf -lft -lm -g

ifeq ($(OS),Windows_NT)
	TARGET_SYSTEM := Windows
else
	TARGET_SYSTEM := $(shell uname -s)
	TARGET_SYSTEM := $(patsubst CYGWIN%,Cygwin,$(TARGET_SYSTEM))
    TARGET_SYSTEM := $(patsubst MSYS%,MSYS,$(TARGET_SYSTEM))
    TARGET_SYSTEM := $(patsubst MINGW%,MSYS,$(TARGET_SYSTEM))
endif

ifeq ($(TARGET_SYSTEM),Windows)
	INCLUDES = $(WIN_INCLUDE_PATHS)
	LIBS = $(WIN_LIBRARY_PATHS)
	CFLAGS = $(WIN_COMPILER_FLAGS)
	LDFLAGS = $(WIN_LINK_FLAGS)
	LIBFT = $(LIBFT_WIN)
	SLASH = \\
	MKDIR = mkdir
	RM = del /s/q
else
	INCLUDES = $(LINUX_INCLUDE_PATHS)
	LIBS = $(LINUX_LIBRARY_PATHS)
	CFLAGS = $(LINUX_COMPILER_FLAGS)
	LDFLAGS = $(LINUX_LINK_FLAGS)
	LIBFT = $(LIBFT_LINUX)
	SLASH = /
	MKDIR := mkdir -p
	RM = /bin/rm -rf
ifndef ($(shell command -v sdl2-config 2> /dev/null))
	SDL_VERSION := ""
else
	SDL_VERSION := $(shell sdl2-config --version)
endif
endif

SRC_LIST = \
	$(SLASH)main.c \
	$(SLASH)utilities$(SLASH)error_output.c \
	# vec_math/vec2_a.c \
	# vec_math/vec2_b.c \
	# update_player/key_input.c \
	# update_player/mouse_handle.c \
	# update_player/movement.c \
	# update_player/update_player.c \
	# update_screen/draw_shapes.c \
	# update_screen/put_pixel.c \
	# update_screen/update_screen.c \
	# update_screen/draw_tex_pixel.c \
	# update_screen/steplen.c \
	# update_screen/draw_2d.c \
	# update_screen/update_sector.c \
	# update_screen/transform_matrix_2d.c \
	# utilities/setup.c \
	# utilities/audio.c \
	# utilities/linkedlist.c \
	# raycaster/line_line_intersection.c \
	# raycaster/get_wall_points.c \
	# raycaster/setup_frame.c \
	# raycaster/recursion_checks.c \
	# raycaster/get_distance.c \
	# raycaster/scan_fov.c \
	# raycaster/ft_calc_distances.c \
	# raycaster/draw_ground.c \
	# raycaster/draw_segment.c \
	# parsing/read_map.c	\
	# parsing/parse_sector.c \
	# porting/png.c \
	# porting/create_mapfile.c \
	# porting/open_file1.c \
	# porting/open_file2.c \

HEADERS = $(addprefix $S,\
		$(SLASH)wolf3d.h\
	)
SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

$O:
	$(MKDIR) $@
	$(MKDIR) $@$(SLASH)utilities
	$(MKDIR) $@$(SLASH)update_player
	$(MKDIR) $@$(SLASH)update_screen
	$(MKDIR) $@$(SLASH)parsing
	$(MKDIR) $@$(SLASH)porting
	$(MKDIR) $@$(SLASH)raycaster
	$(MKDIR) $@$(SLASH)vec_math

$(OBJ): | $O

$(OBJ): $O%.o: $S% $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -C libft

dependencies:
ifeq ($(TARGET_SYSTEM), Linux)
ifeq ($(SDL_VERSION), 2.0.10)
		@if [ ! -d "SDL2_mixer_linux/build" ]; then \
		cd SDL2_mixer_linux && ./configure && make && sudo make install; \
		fi
else
		@echo "Installing project dependencies."
		@echo $(SDL_VERSION)
		@sudo apt-get install libsdl2-dev libsdl2-mixer-2.0-0 libsdl2-ttf-dev
		@if [ ! -d "SDL2_mixer_linux/build" ]; then \
		cd SDL2_mixer_linux && ./configure && make && sudo make install; \
		fi
		@echo "Dependencies installed."
endif
endif

$(NAME): $(LIBFT) dependencies $(OBJ)
	$(CC) $(OBJ) $(LIBS) $(LDFLAGS) -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir
ifeq ($(TARGET_SYSTEM), Linux)
	make -C SDL2_mixer_linux/ clean
endif
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all
