#pragma once

#include <stdbool.h>

#define TILE_TYPES 6

#define GRASS  0
#define WATER  1
#define STREAM 2
#define BUSH   3
#define PATH   4
#define WALL   5

// these arrays are ordered lists of attributes for each tile
char *tile_names[TILE_TYPES];
char tile_chars[TILE_TYPES];
int tile_colors[TILE_TYPES];

// these functions allow the programmer to 'search' for a tile
int tile_index_from_name(char *name);
int tile_index_from_char(char chr);

// returns the 'direction' (u,d,l,r) of a adjacent tile
// of the given type. 'x' if there is no matching tyle.
char adjacent_tile_of_type(int x, int y, int tile_type);

bool tile_is_solid(char tile_char);
