# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2021/04/15 18:00:11 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
S = srcs
O = objs

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

LIBFT_WIN = libft\libft.a
LIBFT_LINUX = libft/libft.a

WIN_INCLUDE_PATHS = \
	-ISDL2-2.0.14\i686-w64-mingw32\include\SDL2 \
	-ISDL2_mixer-2.0.4\i686-w64-mingw32\include\SDL2 \
	-Ilibft
LINUX_INCLUDE_PATHS = -ISDL2-2.0.14/build/include/SDL2 -Ilibft

WIN_LIBRARY_PATHS = \
	-LSDL2-2.0.14\i686-w64-mingw32\lib \
	-LSDL2_mixer-2.0.4\i686-w64-mingw32\lib \
	-Llibft
LINUX_LIBRARY_PATHS = -LSDL2-2.0.14/build/lib -Llibft

WIN_COMPILER_FLAGS = -Wall -Wextra -Werror
LINUX_COMPILER_FLAGS = -Wall -Wextra -Werror -O3

WIN_LINK_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lft -lm
LINUX_LINK_FLAGS = -lSDL2 -lSDL2main -lSDL2_mixer -lft -lm

ifeq ($(OS),Windows_NT)
	TARGET_SYSTEM := Windows
else
	TARGET_SYSTEM := $(shell uname -s)
	TARGET_SYSTEM := $(patsubst CYGWIN%,Cygwin,$(TARGET_SYSTEM))
	TARGET_SYSTEM := $(patsubst MSYS%,MSYS,$(TARGET_SYSTEM))
	TARGET_SYSTEM := $(patsubst MINGW%,MSYS,$(TARGET_SYSTEM))
endif

ifeq ($(TARGET_SYSTEM),Windows)
	NAME = wolf3d.exe
	INCLUDES = $(WIN_INCLUDE_PATHS)
	LIBS = $(WIN_LIBRARY_PATHS)
	CFLAGS = $(WIN_COMPILER_FLAGS)
	LDFLAGS = $(WIN_LINK_FLAGS)
	LIBFT = $(LIBFT_WIN)
	SDL2_BUILD := .\SDL2-2.0.14\i686-w64-mingw32
	SLASH = \\
	MKDIR = mkdir
	RM = del /s/q
	WGET_EXISTS := wget_not_needed
	RESET := [0m
	RED := [31m
	GREEN := [32m
	YELLOW := [33m
	BLUE := [34m
	MAGENTA := [35m
	CYAN := [36m
	WHITE := [37m
else
	INCLUDES = $(LINUX_INCLUDE_PATHS)
	LIBS = $(LINUX_LIBRARY_PATHS)
	CFLAGS = $(LINUX_COMPILER_FLAGS)
	LDFLAGS = $(LINUX_LINK_FLAGS)
	LIBFT = $(LIBFT_LINUX)
	SDL2_BUILD = SDL2-2.0.14/build
	SDL2_FULL_PATH = $(shell pwd)/$(SDL2_BUILD)
	SLASH = /
	MKDIR := mkdir -p
	RM = /bin/rm -rf
	WGET_EXISTS := $(shell command -v wget 2> /dev/null)
	RESET = "\033[0m"
	RED = "\033[0;31m"
	GREEN = "\033[0;32m"
	YELLOW = "\033[0;33m"
	BLUE = "\033[0;34m"
	MAGENTA = "\033[0;35m"
	CYAN = "\033[0;36m"
	WHITE = "\033[0;37m"
endif

LOGO = "\
\t\t                                       88    ad88\n\
\t                                               88   d87\n\
\t                                               88   88\n\
\t                8b      db      d8   adPPYba.  88 MM88MMM\n\
\t                 8b    d88b    d8  a8       8a 88   88\n\
\t                  8b  d8  8b  d8   8b       d8 88   88\n\
\t                   8bd8    8bd8    78a.   .a87 88   88\n\
\t                    YP      YP       7YbbdP7   88   88\n"\

SRC_LIST = \
	$(SLASH)main.c \
	$(SLASH)parsing$(SLASH)parse_sector.c \
	$(SLASH)parsing$(SLASH)parse_xpm.c \
	$(SLASH)parsing$(SLASH)free_sector.c \
	$(SLASH)parsing$(SLASH)mem_texture_data.c \
	$(SLASH)parsing$(SLASH)calc_norm_vectors.c \
	$(SLASH)parsing$(SLASH)parse_pixel_data.c \
	$(SLASH)parsing$(SLASH)parse_colour_data.c \
	$(SLASH)parsing$(SLASH)parse_number_data.c \
	$(SLASH)porting$(SLASH)textures.c \
	$(SLASH)porting$(SLASH)open_files.c \
	$(SLASH)porting$(SLASH)validate_sectors_data.c \
	$(SLASH)porting$(SLASH)validate_sectors_data_2.c \
	$(SLASH)raycaster$(SLASH)calc_distances.c \
	$(SLASH)raycaster$(SLASH)calc_wall_texels.c \
	$(SLASH)raycaster$(SLASH)colour_functions.c \
	$(SLASH)raycaster$(SLASH)draw_segment.c \
	$(SLASH)raycaster$(SLASH)get_wall_points.c \
	$(SLASH)raycaster$(SLASH)line_line_intersection.c \
	$(SLASH)raycaster$(SLASH)line_segment_check.c \
	$(SLASH)raycaster$(SLASH)recursion_checks.c \
	$(SLASH)raycaster$(SLASH)scan_fov.c \
	$(SLASH)raycaster$(SLASH)setup_frame.c \
	$(SLASH)raycaster$(SLASH)step_one.c \
	$(SLASH)update_player$(SLASH)key_input.c \
	$(SLASH)update_player$(SLASH)mouse_handle.c \
	$(SLASH)update_player$(SLASH)player_move.c \
	$(SLASH)update_player$(SLASH)update_player.c \
	$(SLASH)update_screen$(SLASH)draw_frame.c \
	$(SLASH)update_screen$(SLASH)draw_shapes.c \
	$(SLASH)update_screen$(SLASH)draw_tex_pixel.c \
	$(SLASH)update_screen$(SLASH)put_pixel.c \
	$(SLASH)update_screen$(SLASH)matrix_2d.c \
	$(SLASH)update_screen$(SLASH)update_screen.c \
	$(SLASH)utilities$(SLASH)audio.c \
	$(SLASH)utilities$(SLASH)error_output.c \
	$(SLASH)utilities$(SLASH)setup.c \
	$(SLASH)utilities$(SLASH)str_pxl.c \
	$(SLASH)utilities$(SLASH)pxl_alphabet.c \
	$(SLASH)utilities$(SLASH)pxl_numbers.c \
	$(SLASH)utilities$(SLASH)fps_timer.c \
	$(SLASH)vec_math$(SLASH)vec2_a.c \
	$(SLASH)vec_math$(SLASH)vec2_b.c \
	$(SLASH)vec_math$(SLASH)vec2_c.c \
	$(SLASH)vec_math$(SLASH)vec2_d.c \
	$(SLASH)vec_math$(SLASH)vec3.c \

HEADERS = \
		srcs$(SLASH)wolf3d.h \
		headers$(SLASH)audio.h \
		headers$(SLASH)calculations.h \
		headers$(SLASH)colours.h \
		headers$(SLASH)drawing_functions.h \
		headers$(SLASH)events.h \
		headers$(SLASH)macros.h \
		headers$(SLASH)parsing.h \
		headers$(SLASH)player_functions.h \
		headers$(SLASH)player.h \
		headers$(SLASH)porting.h \
		headers$(SLASH)program.h \
		headers$(SLASH)raycast.h \
		headers$(SLASH)sector.h \
		headers$(SLASH)typewriter.h \
		headers$(SLASH)vectors.h \

SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
CC = gcc

.PHONY: all clean fclean re cleanobj cleanobjdir

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
ifeq ($(TARGET_SYSTEM), Linux)
	@echo $(RED)$(LOGO)$(RESET)
else
	@echo $(RED)                 WOLF3D                   $(RESET)
endif
	make -C libft

$(SDL2_BUILD):
ifndef WGET_EXISTS
	sudo apt-get install wget -y
endif
ifeq ($(TARGET_SYSTEM), Linux)
	@if [ ! -f "SDL2-2.0.14.tar.gz" ]; then \
	wget https://www.libsdl.org/release/SDL2-2.0.14.tar.gz; \
	fi
	@if [ ! -d "SDL2-2.0.14" ]; then \
	tar -xzf SDL2-2.0.14.tar.gz; \
	fi
	@if [ ! -d "SDL2-2.0.14/build" ]; then \
	cd "SDL2-2.0.14" && $(MKDIR) build && cd build && \
	../configure --prefix $(SDL2_FULL_PATH) && \
	make && \
	make install; \
	fi
	@if [ ! -f "SDL2_mixer-2.0.4.tar.gz" ]; then \
	wget https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.tar.gz; \
	fi
	@if [ ! -d "SDL2_mixer-2.0.4" ]; then \
	tar -xzf SDL2_mixer-2.0.4.tar.gz; \
	fi
	@if [ ! -d "SDL2_mixer-2.0.4/build" ]; then \
	cd SDL2_mixer-2.0.4 && $(MKDIR) build && cd build && \
	../configure --prefix $(SDL2_FULL_PATH) && \
	make && \
	make install; \
	fi
else
	@IF NOT EXIST "SDL2-2.0.14\x86_64-w64-mingw32" ( install.bat )\
	ELSE ECHO $(GREEN)"Folder exists."$(RESET)
endif

$(NAME): $(LIBFT) $(SDL2_BUILD) $(OBJ)
	$(CC) -o $@ $(INCLUDES) $(LIBS) $(CFLAGS) $(OBJ) $(LDFLAGS)
	@echo $(GREEN)Compiled executable $(NAME).
	@echo Run the map files $(NAME) map_files/map.TEST.
	@echo Running tests.sh tests executable with invalid maps.$(RESET)

cleanobj:
ifneq ($(wildcard $(OBJ)),)
	@$(RM) $(wildcard $(OBJ))
endif

cleanobjdir: cleanobj
ifeq ($(TARGET_SYSTEM), Linux)
	@$(RM) $O
else
	@IF EXIST $O ( rd /s /q "$O" )
endif

clean: cleanobjdir
ifeq ($(TARGET_SYSTEM), Linux)
	@$(RM) SDL2-2.0.14
	@$(RM) SDL2_mixer-2.0.4
else
	@IF EXIST SDL2-2.0.14 ( $(RM) "SDL2-2.0.14" )
	@IF EXIST SDL2-2.0.14 ( rd /s /q "SDL2-2.0.14" )
	@IF EXIST SDL2_mixer-2.0.4 ( $(RM) "SDL2_mixer-2.0.4" )
	@IF EXIST SDL2_mixer-2.0.4 ( rd /s /q "SDL2_mixer-2.0.4" )
endif
	@make -C libft clean
	@echo $(GREEN)Cleaned folder from object files and SDL2 folder.$(RESET)

fclean: clean
ifeq ($(TARGET_SYSTEM), Windows)
	@IF EXIST $(NAME) ( $(RM) "$(NAME)") \
	ELSE ( ECHO $(CYAN)No binary to remove. $(RESET) )
else
	@$(RM) $(NAME)
endif
	@make -C libft fclean
	@echo $(GREEN)Removed binaries and libraries.$(RESET)

re: fclean all
