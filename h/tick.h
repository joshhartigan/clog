#pragma once

#include <stdbool.h>

// this is essentially a function that makes
// naturally-occuring processes happen.
// e.g. (if the game had gravity), tick() would
// allow gravity to force its effect on the world.
void tick();

// if a path at [x, y] is next to a source of
// water, it will be flooded.
void flood_path(int x, int y);

// is the water at [x, y] attached to a source or
// a stream that is attached to a source?
bool water_has_source(int x, int y);
