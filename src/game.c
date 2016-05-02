#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "game.h"

#include "color.h"
#include "draw.h"
#include "input.h"
#include "map.h"
#include "player.h"
#include "tick.h"

#define ESCAPE_KEY 27

int main() {
  srand(time(NULL));

  window = initscr();

  if (window == NULL) {
    fprintf(stderr, "clog :: error initialising curses.\n");
    return 1;
  }

  start_color();
  if (has_colors() && COLOR_PAIRS >= 13) {
    init_colors();
  }
  curs_set(0); // hide the cursor
  noecho(); // do not show characters when they've been typed
  nodelay(window, true); // don't cause getch() to wait

  generate_map();
  create_player();

  loop();

  quit(window);
}

void loop() {
  char key = '\0';
  while (key != ESCAPE_KEY) {
    tick();
    draw();
    key = getch();
    usleep(50000);
    handle_keypress(key);
  }
}

void quit(WINDOW *window) {
  delwin(window);
  endwin();
  refresh();
}
