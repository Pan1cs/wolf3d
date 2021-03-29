# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2021/03/29 15:47:28 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
S = srcs
O = objs

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

LIBFT_WIN = libft\libft.a
LIBFT_LINUX = libft/libft.a

WIN_INCLUDE_PATHS = -ISDL2\include\SDL2 -Ilibft
LINUX_INCLUDE_PATHS = -I/SDL2/include/SDL2/ -I/usr/include/SDL2 -Ilibft

WIN_LIBRARY_PATHS = -LSDL2\lib -Llibft
LINUX_LIBRARY_PATHS = -L/lib/ -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -Llibft

WIN_COMPILER_FLAGS = -Wall -Wextra -g
LINUX_COMPILER_FLAGS = -Wall -Wextra -Werror -g

WIN_LINK_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lft
LINUX_LINK_FLAGS = -lSDL2 -lSDL2main -lSDL2_mixer -lft -lm -g

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
	SDL2_EXISTS := SDL2_included
else
	INCLUDES = $(LINUX_INCLUDE_PATHS)
	LIBS = $(LINUX_LIBRARY_PATHS)
	CFLAGS = $(LINUX_COMPILER_FLAGS)
	LDFLAGS = $(LINUX_LINK_FLAGS)
	LIBFT = $(LIBFT_LINUX)
	SLASH = /
	MKDIR := mkdir -p
	RM = /bin/rm -rf
	SDL2_EXISTS := $(shell command -v sdl2-config 2> /dev/null)
endif

SRC_LIST = \
	$(SLASH)main.c \
	$(SLASH)parsing$(SLASH)parse_sector.c \
	$(SLASH)parsing$(SLASH)free_sector.c \
	$(SLASH)parsing$(SLASH)calc_norm_vectors.c \
	$(SLASH)porting$(SLASH)textures.c \
	$(SLASH)porting$(SLASH)open_files.c \
	$(SLASH)raycaster$(SLASH)calc_distances.c \
	$(SLASH)raycaster$(SLASH)calc_sector_texels.c \
	$(SLASH)raycaster$(SLASH)calc_wall_texels.c \
	$(SLASH)raycaster$(SLASH)colour_functions.c \
	$(SLASH)raycaster$(SLASH)draw_segment.c \
	$(SLASH)raycaster$(SLASH)get_distance.c \
	$(SLASH)raycaster$(SLASH)get_wall_points.c \
	$(SLASH)raycaster$(SLASH)line_line_intersection.c \
	$(SLASH)raycaster$(SLASH)recursion_checks.c \
	$(SLASH)raycaster$(SLASH)scan_fov.c \
	$(SLASH)raycaster$(SLASH)setup_frame.c \
	$(SLASH)update_player$(SLASH)key_input.c \
	$(SLASH)update_player$(SLASH)mouse_handle.c \
	$(SLASH)update_player$(SLASH)movement.c \
	$(SLASH)update_player$(SLASH)update_player.c \
	$(SLASH)update_screen$(SLASH)draw_frame.c \
	$(SLASH)update_screen$(SLASH)draw_shapes.c \
	$(SLASH)update_screen$(SLASH)draw_tex_pixel.c \
	$(SLASH)update_screen$(SLASH)put_pixel.c \
	$(SLASH)update_screen$(SLASH)steplen.c \
	$(SLASH)update_screen$(SLASH)transform_matrix_2d.c \
	$(SLASH)update_screen$(SLASH)update_screen.c \
	$(SLASH)utilities$(SLASH)audio.c \
	$(SLASH)utilities$(SLASH)debugging.c \
	$(SLASH)utilities$(SLASH)error_output.c \
	$(SLASH)utilities$(SLASH)linkedlist.c \
	$(SLASH)utilities$(SLASH)setup.c \
	$(SLASH)utilities$(SLASH)str_pxl.c \
	$(SLASH)utilities$(SLASH)pxl_alphabet.c \
	$(SLASH)utilities$(SLASH)pxl_numbers.c \
	$(SLASH)vec_math$(SLASH)vec2_a.c \
	$(SLASH)vec_math$(SLASH)vec2_b.c \
	$(SLASH)vec_math$(SLASH)vec2_c.c \
	$(SLASH)vec_math$(SLASH)vec3.c \

HEADERS = $(addprefix $S,\
		$(SLASH)wolf3d.h\
	)
SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
CC = gcc

.PHONY: all clean fclean re dependencies cleanobj cleanobjdir

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
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDES) $<

$(LIBFT):
	make -C libft

dependencies:
ifndef SDL2_EXISTS
	@echo "Installing project dependencies."
	@sudo apt-get install libsdl2-dev libsdl2-mixer-2.0-0 libsdl2-ttf-dev
	@echo "Dependencies installed."
endif
ifeq ($(TARGET_SYSTEM), Linux)
	@if [ ! -d "SDL2_mixer_linux/build" ]; then \
	cd SDL2_mixer_linux && ./configure && make && sudo make install; \
	fi
endif

$(NAME): $(LIBFT) dependencies $(OBJ)
	$(CC) -o $@ $(INCLUDES) $(LIBS) $(CFLAGS) $(OBJ) $(LDFLAGS)

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
ifeq ($(TARGET_SYSTEM), Windows)
	$(RM) $(NAME).exe
else
	$(RM) $(NAME)
endif
	$(RM) $(LIBFT)

re: fclean all
