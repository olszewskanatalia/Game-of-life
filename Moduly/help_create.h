#ifndef HELP_CREATE_H
#define HELP_CREATE_H

#include "structures.h"

int** create_neighbourhood(generation*, neighbour, personal_choice*);

void free_neighbourhood(generation*, int**);

#endif
