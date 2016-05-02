#pragma once

#define DEFAULT_PLAYER_CHAR '@'

#define INVENTORY_SIZE 64

typedef struct {
  int x_pos;
  int y_pos;
  char _char;
  int color;
  int resources;
  char *inventory_names[INVENTORY_SIZE];
  int inventory_values[INVENTORY_SIZE];
} Player;

Player player;

void create_player();
void move_player(char key);

int player_has_item(char *name);
void give_item(char *name, int value);
