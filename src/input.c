#include "input.h"

#include "build.h"
#include "map.h"
#include "player.h"

void handle_keypress(char key) {
  switch (key) {
    case KEY_MOVE_UP:
    case KEY_MOVE_DOWN:
    case KEY_MOVE_LEFT:
    case KEY_MOVE_RIGHT:
      move_player(key);
      break;
    case KEY_LAY_PATH:
      build_path();
      break;
    case KEY_BUILD_WALL:
      build_wall();
      break;
    case KEY_CHOP_TREE:
      chop_tree();
      break;
  }
}
