#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct gene
{
	int** gen;
	int r;
	int c;
	int nr;

}generation;

typedef enum 
{ 
	Mf = 1, Ms = 2, Ns = 3, Nf = 4, Ps = 5, Pf = 6, None = 0 

}neighbour;

typedef struct personal
{	
	int dies;
	int comes_back;
	int personal_neighbours;
	int* neighbours_indexes;

}personal_choice;

#endif
