#include "player.h"

#include "color.h"
#include "input.h"
#include "map.h"
#include "tile.h"

void create_player() {
  player.x_pos = MAP_SIZE_X / 2;
  player.y_pos = MAP_SIZE_Y / 2;
  player._char = DEFAULT_PLAYER_CHAR;
  player.color = RED;
  player.resources = 0;
}

void move_player(char key) {
  int x = player.x_pos;
  int y = player.y_pos;

  if (key == KEY_MOVE_UP &&
      y > 0 &&
      !tile_is_solid(map[x][y - 1])) {
    player.y_pos--;
  }

  if (key == KEY_MOVE_DOWN &&
      y < MAP_SIZE_Y - 1 &&
      !tile_is_solid(map[x][y + 1])) {
    player.y_pos++;
  }

  if (key == KEY_MOVE_LEFT &&
      x > 0 &&
      !tile_is_solid(map[x - 1][y])) {
    player.x_pos--;
  }

  if (key == KEY_MOVE_RIGHT &&
      x < MAP_SIZE_X - 1 &&
      !tile_is_solid(map[x + 1][y])) {
    player.x_pos++;
  }
}
