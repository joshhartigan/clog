#pragma once

void draw(); // 'master function'

// functions for individual elements
void draw_map();
void draw_player();
void draw_status();

// utility function for efficiency
void draw_char(int x, int y, char c);
