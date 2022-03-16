#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "neighbor.h"

int** create_neighbourhood(generation* which_generation, neighbour how, personal_choice* choice)
{
	int  	rows 		= 	which_generation -> r;
	int 	columns 	= 	which_generation -> c;
	int** 	neighbourhood 	= 	(int**) malloc(sizeof(int*) * rows);

	for(int i = 0; i < rows; i++)
	{
		neighbourhood[i] = (int*) malloc(sizeof(int) * columns);
	}

	if(how == Ms)
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0 ; j < columns; j++)
			{
				neighbourhood[i][j] = moore_sphere_world(which_generation, i, j); 
			}
		}
	}
	else if(how == Mf)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = moore_flat_world(which_generation, i, j);
                        }
                }
	}
	else if(how == Ns)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = neumann_sphere_world(which_generation, i, j);
                        }
                }
	}
	else if(how == Nf)
	{
		for(int i = 0; i < rows; i++)
                {
                        for(int j = 0 ; j < columns; j++)
                        {
                                neighbourhood[i][j] = neumann_flat_world(which_generation, i, j);
                        }
                }
	}
	else if(how == Ps)
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				neighbourhood[i][j] = personal_sphere_world(which_generation, i, j, choice);
			}
		}
	}
	else if(how == Pf)
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				neighbourhood[i][j] = personal_flat_world(which_generation, i, j, choice);
			}
		}
	}

	return neighbourhood;
}

void free_neighbourhood(generation* which_generation, int** neighbourhood)
{
	int 	rows 	= 	which_generation -> r;

	for(int i = 0; i < rows; i++)
	{
		free(neighbourhood[i]);
	}

	free(neighbourhood);
}
