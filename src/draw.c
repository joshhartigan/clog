#include <curses.h>
#include <stdlib.h>

#include "draw.h"

#include "color.h"
#include "game.h"
#include "map.h"
#include "player.h"
#include "tile.h"

void draw() {
  draw_map();
  draw_player();
  draw_status();
}

void draw_map() {
  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      int tile_index = tile_index_from_char(map[x][y]);
      if (tile_index == -1) {
        fprintf(stderr, "clog :: the tile at %d,%d is invalid.\n", x, y);
        exit(1);
      }
      color_set(tile_colors[tile_index], NULL);
      draw_char(x, y, map[x][y]);
    }
  }

  refresh();
}

void draw_player() {
  color_set(player.color, NULL);
  draw_char(player.x_pos, player.y_pos, player._char);
}

void draw_status() {
  int top_line_y = MAP_SIZE_Y + 1;
  int status_line_count = 2;
  color_set(WHITE, NULL);

  // clear status lines
  for (int i = 0; i < status_line_count; i++) {
    move(top_line_y + i, 0);
    clrtoeol();
  }

  char status_text[MAP_SIZE_X];

  // first line of status: current tile
  char *floor_name =
    tile_names[tile_index_from_char(map[player.x_pos][player.y_pos])];
  sprintf(status_text, "on: %s", floor_name);
  mvaddstr(top_line_y, 0, status_text);

  // second line of status: resource count
  sprintf(status_text, "res: %d", player.resources);
  mvaddstr(top_line_y + 1, 0, status_text);
}

void draw_char(int x, int y, char c) {
  char str[2] = "\0";
  str[0] = c;
  mvaddstr(y, x, str);
}
