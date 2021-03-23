# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:44:44 by jnivala           #+#    #+#              #
#    Updated: 2021/03/23 15:56:30 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

S = src/
O = obj/
libft_dir = libft/
LIBFT = $(libft_dir)libft.a
LIBS = -lSDL2 -lft
LDFLAGS = -L/usr/local/lib -Llibft/ $(LIBS)
SDL2 = /usr/local/lib/libSDL2.a
SDL2_dir = /usr/local/include/SDL2
include_dirs = $(libft_dir) $(S) $(SDL2_dir)/

SRC_LIST = \
	main.c \
	vec_math/vec2_a.c \
	vec_math/vec2_b.c \
	update_player/key_input.c \
	update_player/mouse_handle.c \
	update_player/movement.c \
	update_player/update_player.c \
	update_screen/draw_shapes.c \
	update_screen/put_pixel.c \
	update_screen/update_screen.c \
	update_screen/draw_tex_pixel.c \
	update_screen/steplen.c \
	update_screen/draw_2d.c \
	update_screen/update_sector.c \
	update_screen/transform_matrix_2d.c \
	utilities/error_output.c \
	utilities/setup.c \
	utilities/audio.c \
	utilities/linkedlist.c \
	raycaster/line_line_intersection.c \
	raycaster/get_wall_points.c \
	raycaster/setup_frame.c \
	raycaster/recursion_checks.c \
	raycaster/get_distance.c \
	raycaster/scan_fov.c \
	raycaster/ft_calc_distances.c \
	raycaster/draw_ground.c \
	raycaster/draw_segment.c \
	parsing/read_map.c	\
	parsing/parse_sector.c \
	porting/png.c \
	porting/create_mapfile.c \
	porting/open_file1.c \
	porting/open_file2.c \

HEADERS = $(addprefix $S,\
		wolf3d.h\
	)
SRC = $(addprefix $S, $(SRC_LIST))
OBJ = $(SRC:$S%=$O%.o)
RM = /bin/rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

WIN_INCLUDE_PATHS = -ISDL2\include\SDL2 -ISDL2_mixer_win\include\SDL2
LINUX_INCLUDE_PATHS = -I/include/SDL2/

WIN_LIBRARY_PATHS = -LSDL2\lib -LSDL2_mixer_win\lib
LINUX_LIBRARY_PATHS = -L/lib/ -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/

WIN_COMPILER_FLAGS = -w
LINUX_COMPILER_FLAGS = -Wall -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$O:
	mkdir -p $@
	mkdir -p $@/utilities
	mkdir -p $@/update_player
	mkdir -p $@/update_screen
	mkdir -p $@/parsing
	mkdir -p $@/porting
	mkdir -p $@/raycaster
	mkdir -p $@/vec_math

$(OBJ): | $O

$(OBJ): $O%.o: $S% $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(libft_dir)

$(SDL2_LINUX):
	sudo apt-get install libsdl2-dev libsdl2-mixer-2.0-0 libsdl2-ttf-dev && \
	cd SDL_mixer && ./configure && make && sudo make install

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

win:
	gcc $(SRCS) -o play $(WIN_INCLUDE_PATHS) $(WIN_LIBRARY_PATHS) $(WIN_COMPILER_FLAGS) $(WIN_LINK_FLAGS)

linux:
	gcc $(SRCS) -g -o play $(LINUX_INCLUDE_PATHS) $(LINUX_LIBRARY_PATHS) $(LINUX_COMPILER_FLAGS) $(LINUX_LINK_FLAGS)

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir
	make -C SDL_mixer/ clean
	make -C $(libft_dir) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all
