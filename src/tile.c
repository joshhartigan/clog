#include <stdbool.h>
#include <string.h>

#include "tile.h"

#include "color.h"
#include "map.h"

char *tile_names[TILE_TYPES] = {
  "grass",
  "water",
  "stream",
  "bush",
  "path",
  "wall",
  "tree",
};

char tile_chars[TILE_TYPES] = {
  '.',
  'O',
  'o',
  ',',
  '=',
  '#',
  'T',
};

int tile_colors[TILE_TYPES] = {
  GREEN,
  BLUE,
  BLUE,
  GREEN,
  YELLOW,
  YELLOW,
  GREEN,
};

int tile_index_from_name(char *name) {
  for (int i = 0; i < TILE_TYPES; i++) {
    if (strcmp(tile_names[i], name) == 0) return i;
  }

  return -1;
}

int tile_index_from_char(char chr) {
  for (int i = 0; i < TILE_TYPES; i++) {
    if (tile_chars[i] == chr) return i;
  }

  return -1;
}

char adjacent_tile_of_type(int x, int y, int tile_type) {
  if (map[x + 1][y] == tile_chars[tile_type]) return 'r';
  else if (map[x - 1][y] == tile_chars[tile_type]) return 'l';
  else if (map[x][y + 1] == tile_chars[tile_type]) return 'd';
  else if (map[x][y - 1] == tile_chars[tile_type]) return 'u';
  else return 'x';
}

bool tile_is_solid(char tile_char) {
  return (tile_index_from_char(tile_char) == WALL);
}
