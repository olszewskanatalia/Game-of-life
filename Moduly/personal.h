#ifndef PERSONAL_H
#define PERSONAL_H

#include "structures.h"

personal_choice* create_personal(int);

personal_choice* personal_mode_interface();

void free_personal(personal_choice*);

#endif
