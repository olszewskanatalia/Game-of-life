#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "structures.h"

int personal_flat_world(generation*, int, int, personal_choice*);

int personal_sphere_world(generation*, int, int, personal_choice*);

int moore_sphere_world(generation*, int, int);

int moore_flat_world(generation*, int, int);

int neumann_sphere_world(generation*, int, int);

int neumann_flat_world(generation*, int, int);

#endif
