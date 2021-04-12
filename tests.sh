#!/bin/bash
valgrind --leak-check=full ./wolf3d map_files/map_error_noheader.TEST
valgrind --leak-check=full ./wolf3d map_files/map_error_samepoints.TEST
valgrind --leak-check=full ./wolf3d map_files/map_error_uncorrect_nb_of_sectors.TEST
valgrind --leak-check=full ./wolf3d map_files/map_error_uncorrect_whitespace.TEST
valgrind --leak-check=full ./wolf3d map_files/map_error_unlinked_map.TEST
