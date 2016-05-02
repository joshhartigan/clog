#include <stdbool.h>

#include "tick.h"

#include "map.h"
#include "tile.h"

void tick() {
  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      if (map[x][y] == tile_chars[PATH]) {
        flood_path(x, y);
      }
      // if (tile is another type) { do stuff }
    }
  }
}

void flood_path(int x, int y) {
  char adjacent_water = adjacent_tile_of_type(x, y, WATER);
  if (adjacent_water == 'x') {
    adjacent_water = adjacent_tile_of_type(x, y, STREAM);
  }

  if (adjacent_water != 'x') {
    map[x][y] = tile_chars[STREAM];
  }
}
