#ifndef MANAGE_GENERATIONS_H
#define MANAGE_GENERATIONS_H


void free_generation(generation*);

generation* create_generation(int, int);

void print_to_output(generation*, char*);

generation* read_generation(char*);


#endif
