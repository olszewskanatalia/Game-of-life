#ifndef MODES_H
#define MODES_H

int the_same(generation*, generation*);

void print_generation(generation*, char*);

void make_copy(generation*, generation*);

generation* fast(generation*, int, neighbour, char, int, int, int, personal_choice*);

generation* sbs(generation*, int, neighbour, char, int, personal_choice*);

#endif
