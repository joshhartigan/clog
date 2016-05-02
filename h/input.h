#pragma once

// movement
#define KEY_MOVE_LEFT  'h'
#define KEY_MOVE_DOWN  'j'
#define KEY_MOVE_UP    'k'
#define KEY_MOVE_RIGHT 'l'

// building / destroying
#define KEY_LAY_PATH   'b'
#define KEY_BUILD_WALL 'w'

void handle_keypress(char key);
