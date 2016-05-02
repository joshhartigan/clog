#pragma once

#define DEFAULT_PLAYER_CHAR '@'

typedef struct {
  int x_pos;
  int y_pos;
  char _char;
  int color;
  int resources;
} Player;

Player player;

void create_player();
void move_player(char key);
