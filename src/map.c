#include <stdlib.h>

#include "map.h"

#include "game.h"
#include "tile.h"

void generate_map() {
  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      int chance = rand() % 10000;

      if (chance < 72) {
        map[x][y] = tile_chars[WATER];
      }

      else if (chance < 400) {
        map[x][y] = tile_chars[TREE];
      }

      else if (chance < 800) {
        map[x][y] = tile_chars[BUSH];
      }

      else map[x][y] = tile_chars[GRASS];
    }
  }
}
