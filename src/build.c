#include "build.h"

#include "map.h"
#include "player.h"
#include "tile.h"

void build_path() {
  int x = player.x_pos;
  int y = player.y_pos;

  // grass can be path'd immediately
  if (map[x][y] == tile_chars[GRASS]) {
    map[x][y] = tile_chars[PATH];
    player.resources++;
  }
  // bushes will be trimmed into grass
  else if (map[x][y] == tile_chars[BUSH]) {
    map[x][y] = tile_chars[GRASS];
    player.resources++;
  }

  // other tiles will not be affected.
}

void build_wall() {
  int x = player.x_pos;
  int y = player.y_pos;

  if (player.resources < WALL_COST) return;

  if (map[x][y] != tile_chars[WATER] && map[x][y] != tile_chars[STREAM]) {
    map[x][y] = tile_chars[WALL];
    player.resources -= WALL_COST;
  }
}

void chop_tree() {
  int x = player.x_pos;
  int y = player.y_pos;

  if (map[x][y] != tile_chars[TREE]) return;
}
